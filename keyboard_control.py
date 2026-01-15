#!/usr/bin/env python3
# usage:
# brew install ffmpeg
# python3 -m pip install getkey
# python3 -m drone_ctrl.keyboard_control --ip 192.168.4.153 --port 8090 --proto legacy --stream
import argparse
import threading
import time

from getkey import getkey, keys

from drone_ctrl.controller import DroneController, LEGACY, NEW

try:
    from wifi_cam_streamer.streamer import ThreadedHTTPServer, UdpStreamHandler
except Exception:
    ThreadedHTTPServer = None
    UdpStreamHandler = None


def start_stream_server(ip, http_port, udp_port, udp_command, udp_keepalive):
    if ThreadedHTTPServer is None or UdpStreamHandler is None:
        print("Streaming disabled: wifi_cam_streamer not importable")
        return None
    server = ThreadedHTTPServer(("0.0.0.0", http_port), UdpStreamHandler)
    server.udp_addr = (ip, udp_port)
    server.udp_command = udp_command.encode("ascii")[:2].ljust(2, b"\x00")
    server.udp_keepalive = udp_keepalive
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    print("HTTP stream: http://127.0.0.1:%d/stream" % http_port)
    return server


def main():
    parser = argparse.ArgumentParser(description="Keyboard control for WiFi CAM drone")
    parser.add_argument("--ip", default="192.168.4.153", help="Drone IP address")
    parser.add_argument("--port", type=int, default=8090, help="Drone UDP control port")
    parser.add_argument("--proto", choices=[LEGACY, NEW], default=LEGACY, help="Packet format")
    parser.add_argument("--rate", type=float, default=25.0, help="Control send rate (Hz)")
    parser.add_argument("--stream", action="store_true", help="Enable UDP MJPEG stream")
    parser.add_argument("--stream-port", type=int, default=45100, help="HTTP stream port")
    parser.add_argument("--stream-udp-port", type=int, default=8080, help="UDP MJPEG source port")
    parser.add_argument("--stream-cmd", default="Bv", help="2-byte UDP stream command")
    parser.add_argument("--stream-keepalive", type=float, default=1.0, help="Stream keepalive seconds")
    args = parser.parse_args()

    controller = DroneController(args.ip, args.port, proto=args.proto, rate_hz=args.rate)
    controller.set_axes(0.0, 0.0, 0.0, 0.0, normalized=True)
    controller.start()

    if args.stream:
        start_stream_server(
            args.ip,
            args.stream_port,
            args.stream_udp_port,
            args.stream_cmd,
            args.stream_keepalive,
        )

    stop_event = threading.Event()
    last_key_time = {"value": 0.0}

    def update_axes(roll=None, pitch=None, yaw=None, throttle=None):
        controller.set_axes(roll, pitch, yaw, throttle, normalized=True)
        last_key_time["value"] = time.time()

    def key_thread():
        while not stop_event.is_set():
            key = getkey(blocking=True)

            if key == "q":
                stop_event.set()
                return
            if key == "t":
                controller.takeoff()
                continue
            if key == "l":
                controller.land()
                continue
            if key == "e":
                controller.emergency()
                continue
            if key == "c":
                controller.calibrate()
                continue

            if key == keys.UP:
                update_axes(throttle=0.7)
            elif key == keys.DOWN:
                update_axes(throttle=0.0)
            elif key == keys.LEFT:
                update_axes(roll=-0.6)
            elif key == keys.RIGHT:
                update_axes(roll=0.6)
            elif key == "w":
                update_axes(pitch=0.6)
            elif key == "s":
                update_axes(pitch=-0.6)
            elif key == "a":
                update_axes(yaw=-1.0)
            elif key == "d":
                update_axes(yaw=1.0)
            else:
                update_axes(roll=0.0, pitch=0.0, yaw=0.0, throttle=0.0)

    def timeout_thread():
        while not stop_event.is_set():
            if last_key_time["value"] > 0:
                if time.time() - last_key_time["value"] > 0.2:
                    controller.set_axes(0.0, 0.0, 0.0, 0.0, normalized=True)
            time.sleep(0.05)

    print("Controls:")
    print("  Arrow keys: throttle/roll")
    print("  W/S: pitch, A/D: yaw")
    print("  T: takeoff, L: land, E: emergency, C: calibrate")
    print("  Q: quit")

    threads = [
        threading.Thread(target=key_thread, daemon=True),
        threading.Thread(target=timeout_thread, daemon=True),
    ]
    for t in threads:
        t.start()

    try:
        while not stop_event.is_set():
            time.sleep(0.1)
    finally:
        controller.close()


if __name__ == "__main__":
    main()
