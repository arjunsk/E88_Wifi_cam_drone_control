// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "esp_http_server.h"
#include "esp_timer.h"
#include "esp_camera.h"
#include <Arduino.h>
#include "img_converters.h"
#include "esp32-hal-ledc.h"
#include "sdkconfig.h"
#include "drone_index.h"
#include "board_config.h"

#if defined(ARDUINO_ARCH_ESP32) && defined(CONFIG_ARDUHAL_ESP_LOG)
#include "esp32-hal-log.h"
#endif

// LED FLASH setup
#if defined(LED_GPIO_NUM)
#define CONFIG_LED_MAX_INTENSITY 255

int led_duty = 0;
bool isStreaming = false;

#endif

typedef struct {
  int throttle;
  int yaw;
  int pitch;
  int roll;
  int emergency;
  int takeoff;
  int land;
  int calibrate;
} drone_state_t;

static drone_state_t drone_state = {
  .throttle = 0,
  .yaw = 0,
  .pitch = 0,
  .roll = 0,
  .emergency = 0,
  .takeoff = 0,
  .land = 0,
  .calibrate = 0
};

static bool drone_tx_task_started = false;
static uint8_t drone_flags_legacy = 0;
static uint8_t drone_oneshot_takeoff = 0;
static uint8_t drone_oneshot_land = 0;
static uint8_t drone_oneshot_emergency = 0;
static uint8_t drone_oneshot_calibrate = 0;
static uint32_t drone_tx_active_until_ms = 0;
static bool drone_tx_has_activity = false;
// Match keyboard_control.py behavior: continuous keepalive at 25Hz.
static bool drone_keepalive_mode = true;

static uint8_t drone_sanitize_axis(uint8_t value) {
  if (value == 0x66 || value == 0x99) {
    return (uint8_t)(value + 1);
  }
  return value;
}

static uint8_t drone_axis_centered_from_percent(int value) {
  if (value < -100) {
    value = -100;
  } else if (value > 100) {
    value = 100;
  }
  int mapped = (int)roundf(((float)(value + 100) * 255.0f) / 200.0f);
  return drone_sanitize_axis((uint8_t)mapped);
}

static uint8_t drone_throttle_from_percent(int value) {
  if (value < 0) {
    value = 0;
  } else if (value > 100) {
    value = 100;
  }
  int mapped = (int)roundf(((float)value * 255.0f) / 100.0f);
  return (uint8_t)mapped;
}

static uint8_t drone_checksum_legacy(const uint8_t *payload) {
  uint8_t chk = payload[1];
  for (int i = 2; i <= 5; i++) {
    chk ^= payload[i];
  }
  return drone_sanitize_axis(chk);
}

static void drone_activate_tx(uint32_t hold_ms) {
  uint32_t until = millis() + hold_ms;
  if (until > drone_tx_active_until_ms) {
    drone_tx_active_until_ms = until;
  }
}

static bool drone_has_manual_input() {
  return (drone_state.throttle > 0) || (abs(drone_state.yaw) > 1) || (abs(drone_state.pitch) > 1) || (abs(drone_state.roll) > 1);
}

static void drone_tx_send_packet() {
  uint8_t oneshot_takeoff = drone_oneshot_takeoff;
  uint8_t oneshot_land = drone_oneshot_land;
  uint8_t oneshot_emergency = drone_oneshot_emergency;
  uint8_t oneshot_calibrate = drone_oneshot_calibrate;

  uint8_t flags = drone_flags_legacy;
  if (oneshot_takeoff > 0) {
    flags |= 0x01;
    drone_oneshot_takeoff--;
  }
  if (oneshot_land > 0) {
    flags |= 0x02;
    drone_oneshot_land--;
  }
  if (oneshot_emergency > 0) {
    flags |= 0x04;
    drone_oneshot_emergency--;
  }
  if (oneshot_calibrate > 0) {
    flags |= 0x80;
    drone_oneshot_calibrate--;
  }

  uint8_t payload[8];
  payload[0] = 0x66;
  payload[1] = drone_axis_centered_from_percent(drone_state.roll);
  payload[2] = drone_axis_centered_from_percent(drone_state.pitch);
  payload[3] = drone_throttle_from_percent(drone_state.throttle);
  payload[4] = drone_axis_centered_from_percent(drone_state.yaw);
  payload[5] = flags;
  payload[6] = drone_checksum_legacy(payload);
  payload[7] = 0x99;

  Serial.write(payload, sizeof(payload));
}

static void drone_tx_task(void *arg) {
  (void)arg;
  const TickType_t period_ticks = pdMS_TO_TICKS(40);  // 25Hz
  while (true) {
    bool has_oneshot = (drone_oneshot_takeoff > 0) || (drone_oneshot_land > 0) || (drone_oneshot_emergency > 0) || (drone_oneshot_calibrate > 0);
    bool has_manual_input = drone_has_manual_input();
    bool is_active = millis() < drone_tx_active_until_ms;
    bool should_send = drone_keepalive_mode || has_oneshot || has_manual_input || is_active;

    if (should_send) {
      drone_tx_send_packet();
    } else {
      drone_tx_has_activity = false;
    }
    vTaskDelay(period_ticks);
  }
}

#define PART_BOUNDARY "123456789000000000000987654321"
static const char *_STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char *_STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char *_STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\nX-Timestamp: %d.%06d\r\n\r\n";

httpd_handle_t stream_httpd = NULL;
httpd_handle_t camera_httpd = NULL;

typedef struct {
  size_t size;   //number of values used for filtering
  size_t index;  //current value index
  size_t count;  //value count
  int sum;
  int *values;  //array to be filled with values
} ra_filter_t;

static ra_filter_t ra_filter;

static ra_filter_t *ra_filter_init(ra_filter_t *filter, size_t sample_size) {
  memset(filter, 0, sizeof(ra_filter_t));

  filter->values = (int *)malloc(sample_size * sizeof(int));
  if (!filter->values) {
    return NULL;
  }
  memset(filter->values, 0, sample_size * sizeof(int));

  filter->size = sample_size;
  return filter;
}

#if ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO
static int ra_filter_run(ra_filter_t *filter, int value) {
  if (!filter->values) {
    return value;
  }
  filter->sum -= filter->values[filter->index];
  filter->values[filter->index] = value;
  filter->sum += filter->values[filter->index];
  filter->index++;
  filter->index = filter->index % filter->size;
  if (filter->count < filter->size) {
    filter->count++;
  }
  return filter->sum / filter->count;
}
#endif

#if defined(LED_GPIO_NUM)
void enable_led(bool en) {  // Turn LED On or Off
  int duty = en ? led_duty : 0;
  if (en && isStreaming && (led_duty > CONFIG_LED_MAX_INTENSITY)) {
    duty = CONFIG_LED_MAX_INTENSITY;
  }
  ledcWrite(LED_GPIO_NUM, duty);
  //ledc_set_duty(CONFIG_LED_LEDC_SPEED_MODE, CONFIG_LED_LEDC_CHANNEL, duty);
  //ledc_update_duty(CONFIG_LED_LEDC_SPEED_MODE, CONFIG_LED_LEDC_CHANNEL);
  log_i("Set LED intensity to %d", duty);
}
#endif

static esp_err_t stream_handler(httpd_req_t *req) {
  camera_fb_t *fb = NULL;
  struct timeval _timestamp;
  esp_err_t res = ESP_OK;
  size_t _jpg_buf_len = 0;
  uint8_t *_jpg_buf = NULL;
  char *part_buf[128];

  static int64_t last_frame = 0;
  if (!last_frame) {
    last_frame = esp_timer_get_time();
  }

  res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
  if (res != ESP_OK) {
    return res;
  }

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  httpd_resp_set_hdr(req, "X-Framerate", "60");

#if defined(LED_GPIO_NUM)
  isStreaming = true;
  enable_led(true);
#endif

  while (true) {
    fb = esp_camera_fb_get();
    if (!fb) {
      log_e("Camera capture failed");
      res = ESP_FAIL;
    } else {
      _timestamp.tv_sec = fb->timestamp.tv_sec;
      _timestamp.tv_usec = fb->timestamp.tv_usec;
      if (fb->format != PIXFORMAT_JPEG) {
        bool jpeg_converted = frame2jpg(fb, 80, &_jpg_buf, &_jpg_buf_len);
        esp_camera_fb_return(fb);
        fb = NULL;
        if (!jpeg_converted) {
          log_e("JPEG compression failed");
          res = ESP_FAIL;
        }
      } else {
        _jpg_buf_len = fb->len;
        _jpg_buf = fb->buf;
      }
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
    }
    if (res == ESP_OK) {
      size_t hlen = snprintf((char *)part_buf, 128, _STREAM_PART, _jpg_buf_len, _timestamp.tv_sec, _timestamp.tv_usec);
      res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
    }
    if (res == ESP_OK) {
      res = httpd_resp_send_chunk(req, (const char *)_jpg_buf, _jpg_buf_len);
    }
    if (fb) {
      esp_camera_fb_return(fb);
      fb = NULL;
      _jpg_buf = NULL;
    } else if (_jpg_buf) {
      free(_jpg_buf);
      _jpg_buf = NULL;
    }
    if (res != ESP_OK) {
      log_e("Send frame failed");
      break;
    }
    int64_t fr_end = esp_timer_get_time();

    int64_t frame_time = fr_end - last_frame;
    last_frame = fr_end;

    frame_time /= 1000;
#if ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO
    uint32_t avg_frame_time = ra_filter_run(&ra_filter, frame_time);
#endif
    log_i(
      "MJPG: %uB %ums (%.1ffps), AVG: %ums (%.1ffps)", (uint32_t)(_jpg_buf_len), (uint32_t)frame_time, 1000.0 / (uint32_t)frame_time, avg_frame_time,
      1000.0 / avg_frame_time
    );
  }

#if defined(LED_GPIO_NUM)
  isStreaming = false;
  enable_led(false);
#endif

  return res;
}

static esp_err_t parse_get(httpd_req_t *req, char **obuf) {
  char *buf = NULL;
  size_t buf_len = 0;

  buf_len = httpd_req_get_url_query_len(req) + 1;
  if (buf_len > 1) {
    buf = (char *)malloc(buf_len);
    if (!buf) {
      httpd_resp_send_500(req);
      return ESP_FAIL;
    }
    if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
      *obuf = buf;
      return ESP_OK;
    }
    free(buf);
  }
  httpd_resp_send_404(req);
  return ESP_FAIL;
}

static esp_err_t cmd_handler(httpd_req_t *req) {
  char *buf = NULL;
  char variable[32];
  char value[32];

  if (parse_get(req, &buf) != ESP_OK) {
    return ESP_FAIL;
  }
  if (httpd_query_key_value(buf, "var", variable, sizeof(variable)) != ESP_OK || httpd_query_key_value(buf, "val", value, sizeof(value)) != ESP_OK) {
    free(buf);
    httpd_resp_send_404(req);
    return ESP_FAIL;
  }
  free(buf);

  int val = atoi(value);
  int res = 0;

  if (!strcmp(variable, "throttle")) {
    int prev = drone_state.throttle;
    drone_state.throttle = val;
    if (val != prev) {
      if (val != 0) {
        drone_tx_has_activity = true;
        drone_activate_tx(300);
      } else if (prev != 0 && drone_tx_has_activity) {
        // Send neutral frame(s) briefly after stick release, then stop.
        drone_activate_tx(300);
      }
    }
  } else if (!strcmp(variable, "yaw")) {
    int prev = drone_state.yaw;
    drone_state.yaw = val;
    if (val != prev) {
      if (val != 0) {
        drone_tx_has_activity = true;
        drone_activate_tx(300);
      } else if (prev != 0 && drone_tx_has_activity) {
        drone_activate_tx(300);
      }
    }
  } else if (!strcmp(variable, "pitch")) {
    int prev = drone_state.pitch;
    drone_state.pitch = val;
    if (val != prev) {
      if (val != 0) {
        drone_tx_has_activity = true;
        drone_activate_tx(300);
      } else if (prev != 0 && drone_tx_has_activity) {
        drone_activate_tx(300);
      }
    }
  } else if (!strcmp(variable, "roll")) {
    int prev = drone_state.roll;
    drone_state.roll = val;
    if (val != prev) {
      if (val != 0) {
        drone_tx_has_activity = true;
        drone_activate_tx(300);
      } else if (prev != 0 && drone_tx_has_activity) {
        drone_activate_tx(300);
      }
    }
  } else if (!strcmp(variable, "emergency")) {
    drone_state.emergency = val;
    if (val > 0) {
      drone_tx_has_activity = true;
      drone_oneshot_emergency = 20;
      drone_activate_tx(1200);
    }
  } else if (!strcmp(variable, "takeoff")) {
    drone_state.takeoff = val;
    if (val > 0) {
      drone_tx_has_activity = true;
      drone_oneshot_takeoff = 20;
      drone_activate_tx(1200);
    }
  } else if (!strcmp(variable, "land")) {
    drone_state.land = val;
    if (val > 0) {
      drone_tx_has_activity = true;
      drone_oneshot_land = 20;
      drone_activate_tx(1200);
    }
  } else if (!strcmp(variable, "calibrate")) {
    drone_state.calibrate = val;
    if (val > 0) {
      drone_tx_has_activity = true;
      drone_oneshot_calibrate = 20;
      drone_activate_tx(1200);
    }
  } else if (!strcmp(variable, "keepalive")) {
    drone_keepalive_mode = (val > 0);
    if (drone_keepalive_mode) {
      drone_tx_has_activity = true;
    }
  }
#if defined(LED_GPIO_NUM)
  else if (!strcmp(variable, "led_intensity")) {
    led_duty = val;
    if (isStreaming) {
      enable_led(true);
    }
  }
#endif
  else {
    log_i("Unknown command: %s", variable);
    res = -1;
  }

  if (res < 0) {
    return httpd_resp_send_500(req);
  }

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  return httpd_resp_send(req, NULL, 0);
}

static esp_err_t index_handler(httpd_req_t *req) {
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, drone_index_html, HTTPD_RESP_USE_STRLEN);
}

void startCameraServer() {
  if (!drone_tx_task_started) {
    drone_tx_task_started = true;
    xTaskCreate(drone_tx_task, "drone_tx_task", 4096, NULL, 1, NULL);
    log_i("Drone TX task started on UART0 TX (GPIO1) at 19200 baud");
  }

  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.max_uri_handlers = 4;

  httpd_uri_t index_uri = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = index_handler,
    .user_ctx = NULL
#ifdef CONFIG_HTTPD_WS_SUPPORT
    ,
    .is_websocket = true,
    .handle_ws_control_frames = false,
    .supported_subprotocol = NULL
#endif
  };

  httpd_uri_t cmd_uri = {
    .uri = "/control",
    .method = HTTP_GET,
    .handler = cmd_handler,
    .user_ctx = NULL
#ifdef CONFIG_HTTPD_WS_SUPPORT
    ,
    .is_websocket = true,
    .handle_ws_control_frames = false,
    .supported_subprotocol = NULL
#endif
  };

  httpd_uri_t stream_uri = {
    .uri = "/stream",
    .method = HTTP_GET,
    .handler = stream_handler,
    .user_ctx = NULL
#ifdef CONFIG_HTTPD_WS_SUPPORT
    ,
    .is_websocket = true,
    .handle_ws_control_frames = false,
    .supported_subprotocol = NULL
#endif
  };

  ra_filter_init(&ra_filter, 20);

  log_i("Starting web server on port: '%d'", config.server_port);
  if (httpd_start(&camera_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(camera_httpd, &index_uri);
    httpd_register_uri_handler(camera_httpd, &cmd_uri);
  }

  config.server_port += 1;
  config.ctrl_port += 1;
  log_i("Starting stream server on port: '%d'", config.server_port);
  if (httpd_start(&stream_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(stream_httpd, &stream_uri);
  }
}

void setupLedFlash() {
#if defined(LED_GPIO_NUM)
  ledcAttach(LED_GPIO_NUM, 5000, 8);
#else
  log_i("LED flash is disabled -> LED_GPIO_NUM undefined");
#endif
}
