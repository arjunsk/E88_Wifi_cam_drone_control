#!/usr/bin/env python3
# usage : python3 wifi_cam_streamer/streamer.py --ip 192.168.4.153 --source udp --udp-port 8080 --udp-command Bv

import argparse
import http.server
import os
import socket
import subprocess
import sys
import threading
import time

BOUNDARY = b"--WIFI_CAM_STREAM"

RTSP_FRONT = "rtsp://%s:554/avi_rt/front.sd"
RTSP_REAR = "rtsp://%s:554/avi_rt/rear.sd"
RTSP_H264 = "rtsp://%s:554/264_rt/XXX.sd"
RTSP_H264_REAR = "rtsp://%s:554/264_rt/rear.sd"


def which(cmd):
    for path in os.environ.get("PATH", "").split(os.pathsep):
        candidate = os.path.join(path, cmd)
        if os.path.isfile(candidate) and os.access(candidate, os.X_OK):
            return candidate
    return None


def jpeg_frames_from_pipe(pipe):
    buf = bytearray()
    soi = b"\xff\xd8"
    eoi = b"\xff\xd9"
    while True:
        chunk = pipe.read(4096)
        if not chunk:
            return
        buf.extend(chunk)
        while True:
            start = buf.find(soi)
            if start == -1:
                if len(buf) > 2 * 1024 * 1024:
                    buf.clear()
                break
            end = buf.find(eoi, start + 2)
            if end == -1:
                if start > 0:
                    del buf[:start]
                break
            frame = bytes(buf[start:end + 2])
            del buf[:end + 2]
            yield frame


class StreamHandler(http.server.BaseHTTPRequestHandler):
    server_version = "WiFiCamStreamer/1.0"

    def do_GET(self):
        if self.path not in ("/", "/stream"):
            self.send_response(404)
            self.end_headers()
            return

        if self.path == "/":
            html = (
                "<html><head><title>WiFi CAM Stream</title></head>"
                "<body><img src=\"/stream\" style=\"width:100%\"></body></html>"
            )
            self.send_response(200)
            self.send_header("Content-Type", "text/html")
            self.send_header("Content-Length", str(len(html)))
            self.end_headers()
            self.wfile.write(html.encode("ascii"))
            return

        ffmpeg = which("ffmpeg")
        if not ffmpeg:
            self.send_response(500)
            self.end_headers()
            self.wfile.write(b"ffmpeg not found in PATH")
            return

        rtsp_url = self.server.rtsp_url
        self.send_response(200)
        self.send_header("Content-Type", "multipart/x-mixed-replace; boundary=%s" % BOUNDARY.decode("ascii"))
        self.send_header("Cache-Control", "no-cache")
        self.send_header("Pragma", "no-cache")
        self.end_headers()

        transports = self.server.rtsp_transports
        for transport in transports:
            cmd = [
                ffmpeg,
                "-loglevel",
                "error",
                "-rtsp_transport",
                transport,
                "-i",
                rtsp_url,
                "-vf",
                "fps=15",
                "-f",
                "mjpeg",
                "-q:v",
                "5",
                "pipe:1",
            ]

            proc = None
            try:
                proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                for frame in jpeg_frames_from_pipe(proc.stdout):
                    try:
                        self.wfile.write(BOUNDARY + b"\r\n")
                        self.wfile.write(b"Content-Type: image/jpeg\r\n")
                        self.wfile.write(b"Content-Length: %d\r\n\r\n" % len(frame))
                        self.wfile.write(frame)
                        self.wfile.write(b"\r\n")
                    except (BrokenPipeError, ConnectionResetError):
                        return
            except Exception:
                pass
            finally:
                if proc is not None:
                    proc.kill()
                    proc.wait()


class ThreadedHTTPServer(http.server.ThreadingHTTPServer):
    daemon_threads = True


def build_rtsp_url(ip, mode):
    if mode == "front":
        return RTSP_FRONT % ip
    if mode == "rear":
        return RTSP_REAR % ip
    if mode == "h264":
        return RTSP_H264 % ip
    if mode == "h264_rear":
        return RTSP_H264_REAR % ip
    return mode


def jpeg_frames_from_udp(sock, keepalive=None):
    buf = bytearray()
    soi = b"\xff\xd8"
    eoi = b"\xff\xd9"
    last_keepalive = 0.0
    while True:
        if keepalive is not None and time.time() - last_keepalive >= keepalive["interval"]:
            try:
                sock.sendto(keepalive["data"], keepalive["addr"])
            except OSError:
                pass
            last_keepalive = time.time()
        try:
            data = sock.recv(2048)
        except OSError:
            return
        if not data:
            continue
        buf.extend(data)
        while True:
            start = buf.find(soi)
            if start == -1:
                if len(buf) > 2 * 1024 * 1024:
                    buf.clear()
                break
            end = buf.find(eoi, start + 2)
            if end == -1:
                if start > 0:
                    del buf[:start]
                break
            frame = bytes(buf[start:end + 2])
            del buf[:end + 2]
            yield frame


class UdpStreamHandler(http.server.BaseHTTPRequestHandler):
    server_version = "WiFiCamStreamer/1.0"

    def do_GET(self):
        if self.path not in ("/", "/stream"):
            self.send_response(404)
            self.end_headers()
            return

        if self.path == "/":
            html = (
                "<html><head><title>WiFi CAM Stream</title></head>"
                "<body><img src=\"/stream\" style=\"width:100%\"></body></html>"
            )
            self.send_response(200)
            self.send_header("Content-Type", "text/html")
            self.send_header("Content-Length", str(len(html)))
            self.end_headers()
            self.wfile.write(html.encode("ascii"))
            return

        self.send_response(200)
        self.send_header("Content-Type", "multipart/x-mixed-replace; boundary=%s" % BOUNDARY.decode("ascii"))
        self.send_header("Cache-Control", "no-cache")
        self.send_header("Pragma", "no-cache")
        self.end_headers()

        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.settimeout(2.0)
        try:
            sock.sendto(self.server.udp_command, self.server.udp_addr)
            keepalive = None
            if self.server.udp_keepalive > 0:
                keepalive = {
                    "data": self.server.udp_command,
                    "addr": self.server.udp_addr,
                    "interval": self.server.udp_keepalive,
                }
            for frame in jpeg_frames_from_udp(sock, keepalive):
                try:
                    self.wfile.write(BOUNDARY + b"\r\n")
                    self.wfile.write(b"Content-Type: image/jpeg\r\n")
                    self.wfile.write(b"Content-Length: %d\r\n\r\n" % len(frame))
                    self.wfile.write(frame)
                    self.wfile.write(b"\r\n")
                except (BrokenPipeError, ConnectionResetError):
                    break
        finally:
            sock.close()


def main():
    parser = argparse.ArgumentParser(description="WiFi CAM RTSP to MJPEG streamer")
    parser.add_argument("--ip", required=True, help="Drone IP address")
    parser.add_argument(
        "--source",
        default="rtsp",
        choices=["rtsp", "udp"],
        help="Stream source (rtsp or udp)",
    )
    parser.add_argument(
        "--mode",
        default="front",
        help="front, rear, h264, h264_rear, or full rtsp:// URL",
    )
    parser.add_argument("--port", type=int, default=45100, help="HTTP port")
    parser.add_argument(
        "--rtsp-transport",
        default="tcp,udp",
        help="Comma-separated RTSP transports to try (default: tcp,udp)",
    )
    parser.add_argument(
        "--udp-port",
        type=int,
        default=8080,
        help="UDP port for MJPEG stream (default: 8080)",
    )
    parser.add_argument(
        "--udp-command",
        default="Bv",
        help="2-byte UDP start command (default: Bv)",
    )
    parser.add_argument(
        "--udp-keepalive",
        type=float,
        default=1.0,
        help="Seconds between UDP keepalive commands (0 to disable)",
    )
    args = parser.parse_args()

    if args.source == "udp":
        server = ThreadedHTTPServer(("0.0.0.0", args.port), UdpStreamHandler)
        server.udp_addr = (args.ip, args.udp_port)
        server.udp_command = args.udp_command.encode("ascii")[:2].ljust(2, b"\x00")
        server.udp_keepalive = args.udp_keepalive
        print("UDP source:", "%s:%d" % (args.ip, args.udp_port))
        print("UDP command:", server.udp_command)
    else:
        rtsp_url = build_rtsp_url(args.ip, args.mode)
        server = ThreadedHTTPServer(("0.0.0.0", args.port), StreamHandler)
        server.rtsp_url = rtsp_url
        server.rtsp_transports = [t.strip() for t in args.rtsp_transport.split(",") if t.strip()]
        print("RTSP URL:", rtsp_url)

    print("HTTP stream: http://127.0.0.1:%d/stream" % args.port)

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
