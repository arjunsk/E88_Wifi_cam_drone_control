from __future__ import annotations

import os
import threading
import time
from typing import Dict

import cv2
from flask import Flask, Response, jsonify

app = Flask(__name__)


class JumpState:
    def __init__(self, up_duration: float = 2.0, down_duration: float = 1.0, cooldown: float = 1.0) -> None:
        self._lock = threading.Lock()
        self._phase = "IDLE"
        self._phase_end = 0.0
        self._last_trigger = 0.0
        self._up_duration = up_duration
        self._down_duration = down_duration
        self._cooldown = cooldown

    def trigger(self, now: float) -> None:
        with self._lock:
            if self._phase != "IDLE":
                return
            if now - self._last_trigger < self._cooldown:
                return
            self._last_trigger = now
            self._phase = "GO_UP_TO_2M"
            self._phase_end = now + self._up_duration

    def update(self, now: float) -> None:
        with self._lock:
            if self._phase == "GO_UP_TO_2M" and now >= self._phase_end:
                self._phase = "GO_DOWN_TO_1M"
                self._phase_end = now + self._down_duration
            elif self._phase == "GO_DOWN_TO_1M" and now >= self._phase_end:
                self._phase = "IDLE"
                self._phase_end = 0.0

    def status(self) -> Dict[str, str]:
        with self._lock:
            return {"phase": self._phase}


jump_state = JumpState()
camera_index = int(os.environ.get("CAMERA_INDEX", "0"))
camera = cv2.VideoCapture(camera_index)
camera.set(cv2.CAP_PROP_FRAME_WIDTH, 960)
camera.set(cv2.CAP_PROP_FRAME_HEIGHT, 540)

RED_RATIO_THRESHOLD = 0.008
SAT_MIN = 90
VAL_MIN = 70


def detect_red(frame) -> bool:
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_red_1 = (0, SAT_MIN, VAL_MIN)
    upper_red_1 = (10, 255, 255)
    lower_red_2 = (160, SAT_MIN, VAL_MIN)
    upper_red_2 = (179, 255, 255)
    mask1 = cv2.inRange(hsv, lower_red_1, upper_red_1)
    mask2 = cv2.inRange(hsv, lower_red_2, upper_red_2)
    mask = cv2.bitwise_or(mask1, mask2)
    red_ratio = cv2.countNonZero(mask) / mask.size
    return red_ratio > RED_RATIO_THRESHOLD


def annotate_frame(frame, is_red: bool, phase: str) -> None:
    status_text = f"RED DETECTED: {'YES' if is_red else 'NO'}"
    cv2.putText(frame, status_text, (20, 35), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 255), 2)
    cv2.putText(frame, f"JUMP: {phase}", (20, 70), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (40, 200, 40), 2)


def frame_stream():
    while True:
        ok, frame = camera.read()
        if not ok:
            print("Camera frame read failed. Check permissions or CAMERA_INDEX.")
            placeholder = (255 * (cv2.UMat(540, 960, cv2.CV_8UC3))).get()
            placeholder[:] = (20, 20, 20)
            cv2.putText(
                placeholder,
                "CAMERA NOT AVAILABLE",
                (20, 60),
                cv2.FONT_HERSHEY_SIMPLEX,
                1.0,
                (0, 0, 255),
                2,
            )
            ok, buffer = cv2.imencode(".jpg", placeholder)
            if ok:
                frame_bytes = buffer.tobytes()
                yield (
                    b"--frame\r\n"
                    b"Content-Type: image/jpeg\r\n\r\n" + frame_bytes + b"\r\n"
                )
            time.sleep(0.1)
            continue

        now = time.time()
        is_red = detect_red(frame)
        if is_red:
            jump_state.trigger(now)
        jump_state.update(now)
        phase = jump_state.status()["phase"]
        annotate_frame(frame, is_red, phase)

        ok, buffer = cv2.imencode(".jpg", frame)
        if not ok:
            continue
        frame_bytes = buffer.tobytes()
        yield (
            b"--frame\r\n"
            b"Content-Type: image/jpeg\r\n\r\n" + frame_bytes + b"\r\n"
        )


@app.route("/")
def index():
    return (
        "<!doctype html>"
        "<html><head><title>Webcam Jump</title>"
        "<style>"
        "body{font-family:Arial,sans-serif;background:#111;color:#eee;margin:0;padding:20px;}"
        ".wrap{max-width:980px;margin:0 auto;}"
        "img{width:100%;border:2px solid #333;border-radius:8px;}"
        ".status{margin-top:12px;font-size:20px;}"
        ".label{display:inline-block;padding:6px 10px;background:#222;border-radius:6px;}"
        "</style></head><body>"
        "<div class='wrap'>"
        "<h1>Webcam Jump Simulator</h1>"
        "<img src='/video_feed' />"
        "<div class='status'>JUMP COMMAND: <span class='label' id='jump'>IDLE</span></div>"
        "</div>"
        "<script>"
        "async function poll(){"
        "try{const res=await fetch('/status');"
        "const data=await res.json();"
        "document.getElementById('jump').textContent=data.phase;"
        "}catch(e){}"
        "setTimeout(poll,200);"
        "}"
        "poll();"
        "</script></body></html>"
    )


@app.route("/status")
def status():
    return jsonify(jump_state.status())


@app.route("/video_feed")
def video_feed():
    return Response(frame_stream(), mimetype="multipart/x-mixed-replace; boundary=frame")


if __name__ == "__main__":
    port = int(os.environ.get("PORT", "5000"))
    app.run(host="0.0.0.0", port=port, debug=False)
