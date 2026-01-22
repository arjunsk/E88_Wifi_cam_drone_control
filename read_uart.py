

# ls -l /dev/cu.usbserial-1130
# python3 read_uart.py
# in terminal 2, run -> python3 wifi_cam_streamer/send_takeoff.py --ip 192.168.4.153 --ports 8090 --proto both --duration 1.0
# read the output from terminal 1

# Reference: https://github.com/arjunsk/reversing-wifi-uav

# 20
# ['00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00']
# 20
# ['00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0']
# 20
# ['00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00']
# 20
# ['00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0']
# 20
# ['00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00']
# 20
# ['e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0']
# 20
# ['00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00']
# 20
# ['00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00']
# 20
# ['00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0']
# 20
# ['00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00']
# 20
# ['00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0']
# 20
# ['00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00']
# 20
# ['e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0']
# 20
# ['00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00']
# 20
# ['00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00']
# 20
# ['00', 'e0', '00', 'e0', '00', 'e0', '00', '00', '00', '00', 'e0', '00', '00', '00', '00', 'e0', '00', 'e0', '00', 'e0']


####
####
#### This code is to find the buad rate
####
###
# import serial
# import time
# from collections import Counter
# from datetime import datetime

# # ===== USER CONFIG =====
# PORT = "/dev/cu.usbserial-1130"
# DETECT_BAUD = 115200        # just for detecting activity
# DETECT_TIMEOUT = 0.2

# BAUDS_TO_SCAN = [
#     9600,
#     19200,
#     38400,
#     57600,
#     115200,
#     230400,
#     250000,
#     460800,
#     921600,
# ]

# SCAN_TIMEOUT = 0.2
# SCAN_BYTES = 256
# SCAN_INTERVAL = 0.3
# # ======================


# def score(data: bytes) -> float:
#     """
#     Heuristic score:
#       - more unique bytes is good
#       - one byte dominating is bad
#     """
#     if not data:
#         return 0.0
#     c = Counter(data)
#     unique = len(c)
#     top_frac = c.most_common(1)[0][1] / len(data)
#     return unique - 10 * top_frac


# def hexdump_prefix(data: bytes, n=24) -> str:
#     return " ".join(f"{b:02x}" for b in data[:n])


# # ------------------------------------------------------------
# # STEP 1: WAIT FOR ANY ACTIVITY
# # ------------------------------------------------------------
# print(f"[+] Waiting for UART activity on {PORT} @ {DETECT_BAUD} baud")
# print("    → power-cycle device, press buttons, or send commands")

# with serial.Serial(PORT, DETECT_BAUD, timeout=DETECT_TIMEOUT) as ser:
#     ser.reset_input_buffer()
#     while True:
#         b = ser.read(1)
#         if b != b"":
#             print(
#                 f"[+] Activity detected! First byte = 0x{b.hex()} "
#                 f"at {datetime.now().strftime('%H:%M:%S')}"
#             )
#             break

# # Small pause before scanning
# time.sleep(0.3)

# # ------------------------------------------------------------
# # STEP 2: SCAN BAUD RATES
# # ------------------------------------------------------------
# print("\n[+] Starting baud-rate scan")
# print("    (watch for high variety + low repetition)\n")

# while True:
#     for baud in BAUDS_TO_SCAN:
#         try:
#             with serial.Serial(PORT, baud, timeout=SCAN_TIMEOUT) as ser:
#                 ser.reset_input_buffer()
#                 time.sleep(0.05)  # allow buffer to fill
#                 data = ser.read(SCAN_BYTES)

#             if len(data) == 0:
#                 continue

#             c = Counter(data)
#             top_byte, top_cnt = c.most_common(1)[0]
#             top_frac = top_cnt / len(data)

#             print(
#                 f"[{datetime.now().strftime('%H:%M:%S')}] "
#                 f"baud={baud:7d}  "
#                 f"len={len(data):3d}  "
#                 f"unique={len(set(data)):3d}  "
#                 f"top={top_byte:02x}({top_frac:.2f})  "
#                 f"score={score(data):.2f}"
#             )
#             print(f"    data: {hexdump_prefix(data)}\n")

#         except Exception as e:
#             print(f"baud={baud}: ERROR {e}")

#     time.sleep(SCAN_INTERVAL)


import serial

PORT = "/dev/cu.usbserial-1130"
BAUD = 19200
FRAME_LEN = 8

def hexdump(b: bytes) -> str:
    return " ".join(f"{x:02x}" for x in b)

with serial.Serial(PORT, BAUD, timeout=1) as ser:
    print(f"Sniffing {PORT} @ {BAUD} baud, {FRAME_LEN}-byte frames")
    while True:
        frame = ser.read(FRAME_LEN)
        if len(frame) < FRAME_LEN:
            continue
        print(hexdump(frame), frame)

# after fixing the baud rate, the output is more clean
# ➜  drone_ctrl git:(main) ✗ python3 read_uart.py

# Sniffing /dev/cu.usbserial-1130 @ 19200 baud, 8-byte frames
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'
# 66 80 80 00 80 01 81 99 b'f\x80\x80\x00\x80\x01\x81\x99'