import socket
import threading
import time
from dataclasses import dataclass


LEGACY = "legacy"
NEW = "new"


@dataclass
class Axes:
    roll: int = 128
    pitch: int = 128
    yaw: int = 128
    throttle: int = 0


class DroneController:
    def __init__(self, ip, port=2228, proto=LEGACY, rate_hz=25):
        self.ip = ip
        self.port = int(port)
        self.proto = proto
        self.rate_hz = float(rate_hz)
        self.axes = Axes()
        self.flags_legacy = 0
        self.flags_new = 0
        self.flags_new2 = 0
        self._oneshot = {}
        self._lock = threading.Lock()
        self._running = False
        self._thread = None
        self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def close(self):
        self.stop()
        self._sock.close()

    def start(self):
        if self._running:
            return
        self._running = True
        self._thread = threading.Thread(target=self._loop, daemon=True)
        self._thread.start()

    def stop(self):
        self._running = False
        if self._thread is not None:
            self._thread.join(timeout=1.0)
            self._thread = None

    def set_axes(self, roll=None, pitch=None, yaw=None, throttle=None, normalized=True):
        with self._lock:
            if roll is not None:
                self.axes.roll = self._normalize_axis(roll, center=True) if normalized else int(roll)
            if pitch is not None:
                self.axes.pitch = self._normalize_axis(pitch, center=True) if normalized else int(pitch)
            if yaw is not None:
                self.axes.yaw = self._normalize_axis(yaw, center=True) if normalized else int(yaw)
            if throttle is not None:
                self.axes.throttle = self._normalize_axis(throttle, center=False) if normalized else int(throttle)

    def set_flags(self, rotate=None, headless=None, stay_high=None):
        with self._lock:
            if rotate is not None:
                self.flags_legacy = self._set_bit(self.flags_legacy, 3, rotate)
                self.flags_new = self._set_bit(self.flags_new, 3, rotate)
            if headless is not None:
                self.flags_legacy = self._set_bit(self.flags_legacy, 4, headless)
                self.flags_new2 = self._set_bit(self.flags_new2, 0, headless)
            if stay_high is not None:
                self.flags_new2 = self._set_bit(self.flags_new2, 1, stay_high)

    def takeoff(self):
        self._oneshot_flag("takeoff")

    def land(self):
        self._oneshot_flag("land")

    def emergency(self):
        self._oneshot_flag("emergency")

    def calibrate(self):
        self._oneshot_flag("calibrate")

    def send_once(self):
        payload = self._build_packet()
        self._sock.sendto(payload, (self.ip, self.port))

    def _loop(self):
        interval = 1.0 / self.rate_hz
        while self._running:
            payload = self._build_packet()
            try:
                self._sock.sendto(payload, (self.ip, self.port))
            except OSError:
                pass
            time.sleep(interval)

    def _build_packet(self):
        with self._lock:
            axes = Axes(self.axes.roll, self.axes.pitch, self.axes.yaw, self.axes.throttle)
            flags_legacy = self.flags_legacy
            flags_new = self.flags_new
            flags_new2 = self.flags_new2
            oneshot = dict(self._oneshot)

        if oneshot:
            flags_legacy, flags_new, flags_new2 = self._apply_oneshot(flags_legacy, flags_new, flags_new2)

        if self.proto == NEW:
            return self._build_new_packet(axes, flags_new, flags_new2)
        return self._build_legacy_packet(axes, flags_legacy)

    def _build_legacy_packet(self, axes, flags):
        roll = self._sanitize_axis(axes.roll)
        pitch = self._sanitize_axis(axes.pitch)
        yaw = self._sanitize_axis(axes.yaw)
        payload = bytearray(8)
        payload[0] = 0x66
        payload[1] = roll
        payload[2] = pitch
        payload[3] = axes.throttle & 0xFF
        payload[4] = yaw
        payload[5] = flags & 0xFF
        payload[6] = self._checksum_legacy(payload)
        payload[7] = 0x99
        return payload

    def _build_new_packet(self, axes, flags, flags2):
        roll = self._sanitize_axis(axes.roll)
        pitch = self._sanitize_axis(axes.pitch)
        yaw = self._sanitize_axis(axes.yaw)
        payload = bytearray(20)
        payload[0] = 0x66
        payload[1] = 0x14
        payload[2] = roll
        payload[3] = pitch
        payload[4] = axes.throttle & 0xFF
        payload[5] = yaw
        payload[6] = flags & 0xFF
        payload[7] = flags2 & 0xFF
        payload[18] = self._checksum_new(payload)
        payload[19] = 0x99
        return payload

    def _apply_oneshot(self, flags_legacy, flags_new, flags_new2):
        with self._lock:
            max_ticks = 20 if self.proto == LEGACY else 50
            if "takeoff" in self._oneshot:
                flags_legacy |= 0x01
                flags_new |= 0x01
                self._decrement_oneshot("takeoff", max_ticks)
            if "land" in self._oneshot:
                flags_legacy |= 0x02
                flags_new |= 0x01
                self._decrement_oneshot("land", max_ticks)
            if "emergency" in self._oneshot:
                flags_legacy |= 0x04
                flags_new |= 0x02
                self._decrement_oneshot("emergency", max_ticks)
            if "calibrate" in self._oneshot:
                flags_legacy |= 0x80
                flags_new |= 0x04
                self._decrement_oneshot("calibrate", max_ticks)
        return flags_legacy, flags_new, flags_new2

    def _decrement_oneshot(self, key, max_ticks):
        remaining = self._oneshot.get(key, 0)
        remaining -= 1
        if remaining <= 0:
            self._oneshot.pop(key, None)
        else:
            self._oneshot[key] = min(remaining, max_ticks)

    def _oneshot_flag(self, key):
        with self._lock:
            self._oneshot[key] = 20 if self.proto == LEGACY else 50

    @staticmethod
    def _set_bit(value, bit, enabled):
        if enabled:
            return value | (1 << bit)
        return value & ~(1 << bit)

    @staticmethod
    def _normalize_axis(value, center=True):
        if center:
            value = max(-1.0, min(1.0, float(value)))
            return int(round((value + 1.0) * 127.5))
        value = max(0.0, min(1.0, float(value)))
        return int(round(value * 255.0))

    @staticmethod
    def _sanitize_axis(value):
        value = value & 0xFF
        if value in (0x66, 0x99):
            value = (value + 1) & 0xFF
        return value

    @staticmethod
    def _checksum_legacy(payload):
        chk = payload[1]
        for i in range(2, 6):
            chk ^= payload[i]
        return DroneController._sanitize_axis(chk)

    @staticmethod
    def _checksum_new(payload):
        chk = payload[2]
        for i in range(3, 18):
            chk ^= payload[i]
        return DroneController._sanitize_axis(chk)
