import argparse
import time

from .controller import DroneController, LEGACY, NEW


def build_parser():
    parser = argparse.ArgumentParser(description="Send control packets to the E88 WiFi drone.")
    parser.add_argument("--ip", required=True, help="Drone IP address (AP mode)")
    parser.add_argument("--port", type=int, default=2228, help="UDP port (default: 2228)")
    parser.add_argument("--proto", choices=[LEGACY, NEW], default=LEGACY, help="Packet format")
    parser.add_argument("--rate", type=float, default=25.0, help="Send rate in Hz")

    parser.add_argument("--roll", type=float, help="Roll [-1..1] (left/right)")
    parser.add_argument("--pitch", type=float, help="Pitch [-1..1] (forward/back)")
    parser.add_argument("--yaw", type=float, help="Yaw [-1..1] (rotate)")
    parser.add_argument("--throttle", type=float, help="Throttle [0..1] (up/down)")

    parser.add_argument("--rotate", action="store_true", help="Enable rotate flag")
    parser.add_argument("--headless", action="store_true", help="Enable headless mode")
    parser.add_argument("--stay-high", action="store_true", help="Enable stay-high (new proto only)")

    parser.add_argument("--takeoff", action="store_true", help="Trigger one-key takeoff")
    parser.add_argument("--land", action="store_true", help="Trigger one-key land")
    parser.add_argument("--emergency", action="store_true", help="Trigger emergency stop")
    parser.add_argument("--calibrate", action="store_true", help="Trigger calibration")

    parser.add_argument("--duration", type=float, default=0.5, help="Seconds to send control for")
    parser.add_argument("--once", action="store_true", help="Send a single packet then exit")
    return parser


def main():
    parser = build_parser()
    args = parser.parse_args()

    ctrl = DroneController(args.ip, args.port, proto=args.proto, rate_hz=args.rate)
    try:
        ctrl.set_axes(args.roll, args.pitch, args.yaw, args.throttle, normalized=True)
        ctrl.set_flags(rotate=args.rotate, headless=args.headless, stay_high=args.stay_high)

        if args.takeoff:
            ctrl.takeoff()
        if args.land:
            ctrl.land()
        if args.emergency:
            ctrl.emergency()
        if args.calibrate:
            ctrl.calibrate()

        if args.once:
            ctrl.send_once()
            return

        ctrl.start()
        time.sleep(max(0.1, args.duration))
    finally:
        ctrl.close()


if __name__ == "__main__":
    main()
