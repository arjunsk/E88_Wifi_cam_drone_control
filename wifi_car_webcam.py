"""Expose a local HTTP /stream endpoint that proxies the car's RTSP video.

Behavior (based on the Android app sources):
- Video is RTSP at rtsp://192.168.1.1:7070/webcam (see Config.PREVIEW_ADDRESS).
- UDP heartbeats must be sent to 192.168.1.1:7099 with payload [1, 1] every second
  (see SocketClient.HeartBeatTask and UdpComm usage).

This server:
- Keeps the UDP heartbeat alive in a background thread.
- Uses OpenCV to pull RTSP frames and re-encodes them to JPEG.
- Serves a multipart/x-mixed-replace MJPEG stream at /stream for browser clients.

Requirements:
    pip install flask opencv-python-headless

Run:
    python wifi_stream_server.py
Then open: http://localhost:8000/stream
"""

import socket
import threading
import time
from typing import Generator, Iterable

import cv2
from flask import Flask, Response, abort


RTSP_URL = "rtsp://192.168.1.1:7070/webcam"
HEARTBEAT_HOST = "192.168.1.1"
HEARTBEAT_PORT = 7099
HEARTBEAT_PAYLOAD = bytes([1, 1])  # matches SocketClient.debugSend(new byte[]{1,1})

app = Flask(__name__)
_hb_stop = threading.Event()
_hb_thread: threading.Thread | None = None


def start_heartbeat(stop_event: threading.Event, interval: float = 1.0) -> None:
    """Send periodic UDP heartbeats so the car keeps streaming."""
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    while not stop_event.is_set():
        try:
            sock.sendto(HEARTBEAT_PAYLOAD, (HEARTBEAT_HOST, HEARTBEAT_PORT))
        except OSError:
            # Ignore transient network errors; try again next tick
            pass
        stop_event.wait(interval)
    sock.close()


def _open_capture(rtsp_url: str, retry_delay: float = 1.0) -> cv2.VideoCapture:
    """Open an RTSP capture with retry/backoff."""
    while True:
        cap = cv2.VideoCapture(rtsp_url)
        if cap.isOpened():
            return cap
        cap.release()
        time.sleep(retry_delay)


def mjpeg_generator(rtsp_url: str, stop_event: threading.Event) -> Iterable[bytes]:
    """Yield multipart MJPEG chunks from RTSP frames."""
    boundary = b"--frame"
    cap = _open_capture(rtsp_url)

    while not stop_event.is_set():
        ok, frame = cap.read()
        if not ok:
            cap.release()
            time.sleep(0.2)
            cap = _open_capture(rtsp_url)
            continue

        ok, jpeg = cv2.imencode(".jpg", frame, [int(cv2.IMWRITE_JPEG_QUALITY), 80])
        if not ok:
            continue

        chunk = (
            boundary
            + b"\r\nContent-Type: image/jpeg\r\n\r\n"
            + jpeg.tobytes()
            + b"\r\n"
        )
        yield chunk

    cap.release()


def start_background_threads() -> None:
    global _hb_thread
    if _hb_thread is None or not _hb_thread.is_alive():
        _hb_stop.clear()
        _hb_thread = threading.Thread(target=start_heartbeat, args=(_hb_stop,), daemon=True)
        _hb_thread.start()


@app.route("/health")
def health() -> tuple[str, int]:
    return "ok", 200


@app.route("/stream")
def stream() -> Response:
    start_background_threads()

    stop_event = threading.Event()

    def generate() -> Generator[bytes, None, None]:
        try:
            for chunk in mjpeg_generator(RTSP_URL, stop_event):
                yield chunk
        finally:
            stop_event.set()

    return Response(generate(), mimetype="multipart/x-mixed-replace; boundary=frame")


if __name__ == "__main__":
    start_background_threads()
    try:
        app.run(host="0.0.0.0", port=8000, threaded=True)
    finally:
        _hb_stop.set()
        if _hb_thread is not None:
            _hb_thread.join(timeout=1)
