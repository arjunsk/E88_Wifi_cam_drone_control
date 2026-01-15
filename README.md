# E88 WiFi drone control (reverse-engineered from WiFi_CAM)

This is a minimal UDP sender based on `sources/com/tzh/wifi/wificam/model/base/BaseCmd.java`.
The app builds either an 8-byte (legacy) or 20-byte (new) packet and repeatedly sends it.

## Packet formats

Legacy (8 bytes):
- [0] 0x66
- [1] roll (0..255, 128 = center)
- [2] pitch (0..255, 128 = center)
- [3] throttle (0..255, 0 = low)
- [4] yaw (0..255, 128 = center)
- [5] flags
- [6] checksum = XOR bytes [1..5], sanitized to avoid 0x66/0x99
- [7] 0x99

New (20 bytes):
- [0] 0x66
- [1] 0x14
- [2] roll
- [3] pitch
- [4] throttle
- [5] yaw
- [6] flags
- [7] flags2
- [18] checksum = XOR bytes [2..17], sanitized to avoid 0x66/0x99
- [19] 0x99

Flags (legacy):
- bit0 takeoff, bit1 land, bit2 emergency, bit3 rotate, bit4 headless, bit7 calibrate

Flags (new):
- byte6: bit0 takeoff/land, bit1 emergency, bit2 calibrate, bit3 rotate
- byte7: bit0 headless, bit1 stay-high

## Usage

Send a short forward move (legacy protocol):

```bash
python -m drone_ctrl.cli --ip 192.168.4.1 --port 2228 --proto legacy --pitch 0.6 --duration 0.4
```

Takeoff (legacy):

```bash
python -m drone_ctrl.cli --ip 192.168.4.1 --port 2228 --proto legacy --takeoff --duration 0.6
```

Emergency stop:

```bash
python -m drone_ctrl.cli --ip 192.168.4.1 --port 2228 --proto legacy --emergency --duration 0.6
```

## Notes

- The WiFi_CAM Java code does not open sockets; networking happens in native libs.
- Default UDP port is usually `2228` (see `IConstants.AP_MODE_UDP_PORT`).
- If commands do nothing, try:
  - Different IP (common AP IPs: `192.168.4.1`, `192.168.8.1`, `192.168.8.15`).
  - `--proto new` (20-byte packets).
  - Different port (some variants use 9000/8889).

## Keyboard control + stream

This repo includes a keyboard control script that can start the UDP MJPEG stream.

```bash
python3 -m drone_ctrl.keyboard_control --ip 192.168.4.153 --port 8090 --proto legacy --stream
```

## Safety

Use this on the ground first. Keep props clear and have an emergency stop handy.
