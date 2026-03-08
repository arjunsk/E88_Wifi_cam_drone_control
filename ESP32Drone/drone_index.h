#pragma once

static const char drone_index_html[] = R"rawliteral(
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,viewport-fit=cover" />
  <title>Drone Control</title>
  <style>
    :root {
      --safe-top: max(8px, env(safe-area-inset-top));
      --safe-bottom: max(12px, env(safe-area-inset-bottom));
      --ring: rgba(235, 247, 255, 0.52);
      --ring2: rgba(235, 247, 255, 0.26);
    }

    * {
      box-sizing: border-box;
      -webkit-tap-highlight-color: transparent;
      user-select: none;
      touch-action: none;
    }

    html, body {
      margin: 0;
      width: 100%;
      height: 100%;
      overflow: hidden;
      background: #041a2b;
      font-family: "Avenir Next", "Segoe UI", sans-serif;
    }

    .app {
      position: relative;
      width: 100%;
      height: 100dvh;
      overflow: hidden;
      background: radial-gradient(100% 120% at 50% 10%, #0b3b62 0%, #041a2b 60%);
    }

    #stream {
      position: absolute;
      inset: 0;
      width: 100%;
      height: 100%;
      object-fit: cover;
      z-index: 0;
      opacity: 0.98;
    }

    .veil {
      position: absolute;
      inset: 0;
      z-index: 1;
      background: linear-gradient(180deg, rgba(0, 18, 33, 0.22) 0%, rgba(0, 18, 33, 0.4) 100%);
      pointer-events: none;
    }

    .hint {
      position: absolute;
      left: 50%;
      top: var(--safe-top);
      transform: translateX(-50%);
      z-index: 5;
      color: rgba(240, 250, 255, 0.9);
      font-size: 12px;
      background: rgba(2, 15, 26, 0.35);
      border: 1px solid rgba(214, 243, 255, 0.35);
      border-radius: 999px;
      padding: 4px 10px;
      backdrop-filter: blur(4px);
      pointer-events: none;
    }

    .controls {
      position: absolute;
      inset: 0;
      z-index: 4;
      pointer-events: none;
    }

    .stick {
      position: absolute;
      bottom: calc(var(--safe-bottom) + 24px);
      width: min(40vw, 210px);
      aspect-ratio: 1;
      border-radius: 50%;
      border: 3px solid var(--ring);
      background:
        radial-gradient(circle at 50% 50%, rgba(255,255,255,0.07) 0 17%, transparent 18%),
        radial-gradient(circle at 50% 50%, transparent 0 44%, var(--ring2) 45% 47%, transparent 48%),
        rgba(4, 18, 32, 0.28);
      box-shadow: inset 0 0 30px rgba(255,255,255,0.05);
      pointer-events: auto;
    }

    #leftStick { left: 4vw; }
    #rightStick { right: 4vw; }

    .knob {
      position: absolute;
      left: 50%;
      top: 50%;
      width: 36%;
      aspect-ratio: 1;
      transform: translate(-50%, -50%);
      border-radius: 50%;
      border: 2px solid rgba(235, 247, 255, 0.5);
      background: radial-gradient(circle at 30% 30%, #e0f6ff, rgba(190, 227, 244, 0.65));
      box-shadow: 0 10px 24px rgba(0,0,0,.34);
    }

    .stop {
      position: absolute;
      left: 50%;
      bottom: calc(var(--safe-bottom) + 34px);
      transform: translateX(-50%);
      width: min(24vw, 110px);
      aspect-ratio: 1;
      border: 0;
      border-radius: 24px;
      font-size: clamp(20px, 4.6vw, 34px);
      font-weight: 800;
      color: #fff;
      background: linear-gradient(180deg, #ff6072, #d01d33);
      box-shadow: 0 12px 26px rgba(0,0,0,.35);
      pointer-events: auto;
    }

    .stop:active { transform: translateX(-50%) scale(0.98); }

    @media (max-width: 390px) {
      .stick { width: min(42vw, 180px); }
      .stop { width: min(25vw, 96px); border-radius: 20px; }
    }
  </style>
</head>
<body>
  <main class="app">
    <img id="stream" alt="camera stream" />
    <div class="veil"></div>
    <div class="hint" id="hint">CONNECTING</div>

    <section class="controls">
      <div id="leftStick" class="stick" aria-label="Left joystick"><div class="knob"></div></div>
      <div id="rightStick" class="stick" aria-label="Right joystick"><div class="knob"></div></div>
      <button id="stopBtn" class="stop" aria-label="Emergency stop">STOP</button>
    </section>
  </main>

  <script>
    (function () {
      const stream = document.getElementById('stream');
      const hint = document.getElementById('hint');
      const stopBtn = document.getElementById('stopBtn');
      const SEND_INTERVAL_MS = 40;
      const DEADZONE = 0.07;

      const state = {
        axes: { throttle: 0, yaw: 0, pitch: 0, roll: 0 }
      };
      let activeSticks = 0;
      let sendTimer = null;
      let neutralBurstTimer = null;
      let neutralBurstLeft = 0;
      const stickControllers = [];
      const tx = {
        throttle: { inflight: false, lastSent: 0, queued: null },
        yaw: { inflight: false, lastSent: 0, queued: null },
        pitch: { inflight: false, lastSent: 0, queued: null },
        roll: { inflight: false, lastSent: 0, queued: null }
      };

      function sendCommand(variable, value) {
        return fetch('/control?var=' + encodeURIComponent(variable) + '&val=' + encodeURIComponent(value)).catch(() => {});
      }

      function setAxes(partial) {
        Object.keys(partial).forEach((k) => {
          const n = Math.round(partial[k]);
          state.axes[k] = Math.max(-100, Math.min(100, n));
        });
      }

      function sendAxis(name, value, force) {
        const lane = tx[name];
        if (!lane) return;

        if (!force && value === lane.lastSent && !lane.inflight && lane.queued === null) {
          return;
        }

        if (lane.inflight) {
          lane.queued = value;
          return;
        }

        lane.inflight = true;
        lane.queued = null;
        sendCommand(name, value).finally(() => {
          lane.inflight = false;
          lane.lastSent = value;
          if (lane.queued !== null && lane.queued !== lane.lastSent) {
            const queued = lane.queued;
            lane.queued = null;
            sendAxis(name, queued, true);
          }
        });
      }

      function sendAxes(force) {
        sendAxis('throttle', state.axes.throttle, force);
        sendAxis('yaw', state.axes.yaw, force);
        sendAxis('pitch', state.axes.pitch, force);
        sendAxis('roll', state.axes.roll, force);
      }

      function stopSendLoopIfIdle() {
        if (activeSticks === 0 && neutralBurstLeft === 0 && sendTimer) {
          clearInterval(sendTimer);
          sendTimer = null;
        }
      }

      function startSendLoop() {
        if (sendTimer) return;
        sendTimer = setInterval(() => {
          if (activeSticks > 0) {
            sendAxes(false);
          } else if (neutralBurstLeft > 0) {
            sendAxes(true);
            neutralBurstLeft -= 1;
          }
          stopSendLoopIfIdle();
        }, SEND_INTERVAL_MS);
      }

      function queueNeutralBurst() {
        neutralBurstLeft = 6;
        if (neutralBurstTimer) {
          clearTimeout(neutralBurstTimer);
        }
        neutralBurstTimer = setTimeout(() => {
          neutralBurstLeft = 0;
          stopSendLoopIfIdle();
        }, 320);
        startSendLoop();
      }

      function startStream() {
        const host = window.location.hostname;
        const streamUrl = 'http://' + host + ':81/stream?t=' + Date.now();
        stream.src = streamUrl;

        stream.addEventListener('load', () => {
          hint.textContent = 'LIVE';
        });

        stream.addEventListener('error', () => {
          hint.textContent = 'NO STREAM';
        });
      }

      function makeStick(root, mapper) {
        const knob = root.querySelector('.knob');
        let pointerId = null;
        let active = false;

        function apply(nx, ny, shouldSend) {
          const len = Math.hypot(nx, ny);
          const maxLen = Math.max(1, len);
          let x = nx / maxLen;
          let y = ny / maxLen;
          if (Math.abs(x) < DEADZONE) x = 0;
          if (Math.abs(y) < DEADZONE) y = 0;

          const maxPx = (root.clientWidth - knob.clientWidth) / 2;
          knob.style.transform = 'translate(calc(-50% + ' + (x * maxPx) + 'px), calc(-50% + ' + (y * maxPx) + 'px))';
          setAxes(mapper(x, y));
          if (shouldSend) sendAxes(true);
        }

        function point(e) {
          const r = root.getBoundingClientRect();
          const radius = (r.width - knob.clientWidth) / 2;
          return {
            x: (e.clientX - (r.left + r.width / 2)) / radius,
            y: (e.clientY - (r.top + r.height / 2)) / radius
          };
        }

        root.addEventListener('pointerdown', (e) => {
          pointerId = e.pointerId;
          if (!active) {
            active = true;
            activeSticks += 1;
          }
          root.setPointerCapture(pointerId);
          const p = point(e);
          apply(p.x, p.y, true);
          startSendLoop();
        });

        root.addEventListener('pointermove', (e) => {
          if (pointerId !== e.pointerId) return;
          const p = point(e);
          apply(p.x, p.y, true);
        });

        function release(e) {
          if (pointerId !== e.pointerId) return;
          if (root.hasPointerCapture(pointerId)) {
            root.releasePointerCapture(pointerId);
          }
          pointerId = null;
          if (active) {
            active = false;
            activeSticks = Math.max(0, activeSticks - 1);
          }
          apply(0, 0, true);
          queueNeutralBurst();
        }

        root.addEventListener('pointerup', release);
        root.addEventListener('pointercancel', release);

        function forceRelease() {
          if (pointerId === null) return;
          const fake = { pointerId };
          release(fake);
        }

        return { forceRelease };
      }

      const leftStickCtrl = makeStick(document.getElementById('leftStick'), (x, y) => ({
        yaw: x * 100,
        throttle: -y * 100
      }));
      stickControllers.push(leftStickCtrl);

      const rightStickCtrl = makeStick(document.getElementById('rightStick'), (x, y) => ({
        roll: x * 100,
        pitch: -y * 100
      }));
      stickControllers.push(rightStickCtrl);

      stopBtn.addEventListener('click', () => {
        state.axes = { throttle: 0, yaw: 0, pitch: 0, roll: 0 };
        sendAxes(true);
        sendCommand('emergency', 1);
        queueNeutralBurst();
      });

      function resetAllAxes() {
        stickControllers.forEach((ctrl) => ctrl.forceRelease());
        state.axes = { throttle: 0, yaw: 0, pitch: 0, roll: 0 };
        activeSticks = 0;
        sendAxes(true);
        queueNeutralBurst();
      }

      window.addEventListener('blur', resetAllAxes);
      window.addEventListener('pagehide', resetAllAxes);
      document.addEventListener('visibilitychange', () => {
        if (document.hidden) resetAllAxes();
      });

      startStream();
    })();
  </script>
</body>
</html>

)rawliteral";
