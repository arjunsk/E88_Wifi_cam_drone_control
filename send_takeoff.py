#!/usr/bin/env python3
# usage: python3 wifi_cam_streamer/send_takeoff.py --ip 192.168.4.153 --ports 8090 --proto both --duration 1.0


# import argparse
# import socket
# import time

# LEGACY_PACKET = bytes([0x66, 0x80, 0x80, 0x00, 0x80, 0x01, 0x81, 0x99])
# NEW_PACKET = bytes([
#     0x66, 0x14, 0x80, 0x80, 0x00, 0x80, 0x01, 0x00,
#     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#     0x00, 0x00, 0x81, 0x99,
# ])


# def main():
#     parser = argparse.ArgumentParser(description="Send takeoff packets to WiFi_CAM drone")
#     parser.add_argument("--ip", required=True, help="Drone IP address")
#     parser.add_argument(
#         "--ports",
#         default="2228,2224,3333,8080",
#         help="Comma-separated UDP ports to try",
#     )
#     parser.add_argument(
#         "--proto",
#         choices=["legacy", "new", "both"],
#         default="legacy",
#         help="Packet format to send",
#     )
#     parser.add_argument("--rate", type=float, default=25.0, help="Packets per second")
#     parser.add_argument("--duration", type=float, default=1.0, help="Seconds per port")
#     args = parser.parse_args()

#     ports = [int(p.strip()) for p in args.ports.split(",") if p.strip()]
#     packets = []
#     if args.proto in ("legacy", "both"):
#         packets.append(("legacy", LEGACY_PACKET))
#     if args.proto in ("new", "both"):
#         packets.append(("new", NEW_PACKET))

#     sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#     interval = 1.0 / max(args.rate, 1.0)

#     for port in ports:
#         print("Sending to %s:%d" % (args.ip, port))
#         end_time = time.time() + args.duration
#         while time.time() < end_time:
#             for name, pkt in packets:
#                 try:
#                     sock.sendto(pkt, (args.ip, port))
#                 except OSError:
#                     pass
#             time.sleep(interval)

#     sock.close()


# if __name__ == "__main__":
#     main()


#!/usr/bin/env python3
import socket
import time
import argparse

# 8-byte LEGACY control packet
LEGACY_PACKET = bytes([
    0x66,  # header
    0x80,  # roll (center)
    0x80,  # pitch (center)
    0x00,  # throttle (zero)
    0x80,  # yaw (center)
    0x01,  # flags (takeoff / arm?)
    0x81,  # checksum / footer?
    0x99,  # footer
])

def main():
    parser = argparse.ArgumentParser(description="Send LEGACY takeoff packet to WiFi drone")
    parser.add_argument("--ip", required=True, help="Drone IP address")
    parser.add_argument("--port", type=int, default=8090, help="UDP port (default: 8090)")
    parser.add_argument("--rate", type=float, default=25.0, help="Packets per second")
    parser.add_argument("--duration", type=float, default=1.0, help="Seconds to send")
    args = parser.parse_args()

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    interval = 1.0 / max(args.rate, 1.0)
    end_time = time.time() + args.duration

    print(f"Sending LEGACY packet to {args.ip}:{args.port}")
    print(f"rate={args.rate} Hz  duration={args.duration}s")

    while time.time() < end_time:
        sock.sendto(LEGACY_PACKET, (args.ip, args.port))
        time.sleep(interval)

    sock.close()
    print("Done.")

if __name__ == "__main__":
    main()
