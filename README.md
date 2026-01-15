# E88 WiFi drone control (reverse-engineered from WiFi_CAM + VSCode Codex)

This is a minimal UDP sender based on `sources/com/tzh/wifi/wificam/model/base/BaseCmd.java`.
The app builds either an 8-byte (legacy) or ~~20-byte (new)~~ packet and repeatedly sends it.

## Usage
```
brew install ffmpeg
python3 -m pip install getkey

python3 -m drone_ctrl.keyboard_control --ip 192.168.4.153 --port 8090 --proto legacy --stream
```

```
Arrow keys: throttle/roll
W/S: pitch
A/D: yaw
T: takeoff, L: land, E: emergency, C: calibrate
Q: quit
```

## How to do reverse engineering?
1. Download apk from here: https://apkpure.com/wifi-cam/com.tzh.wifi.wificam.activity/download
2. Decompile apk to source here: https://www.decompiler.com/jar/6d076162d2d045bb83092dd7f9e5ca39/WiFi_CAM_6.1.8_APKPure.apk
3. From `step #1`, you could see that the app's main package is `com.tzh.wifi.wificam`. Focus on that package.
4. [Skipped] Now you can follow [these](https://blog.horner.tj/hacking-chinese-drones-for-fun-and-no-profit/) articles, which talk about packet sniffing while the app is running on your phone. For Android, [Wireshark](https://www.apkmirror.com/apk/grey-shirts/packet-capture/packet-capture-1-4-7-release/packet-capture-1-4-7-android-apk-download/) is relatively easy.
5. [Skipped] You can also take a stab at looking at `Logcat` by attaching your Android phone via USB. I didn't have Android Studio installed on my Mac.
6. [Skipped] The core code that talks to the drone is in the `.so` C++ compiled binary code. You could use [Ghidra](https://youtube.com/shorts/4DpV0zdJEk0?si=OEvr-Z2v8rl0pbHy) to take a look at that.
7. [Skipped] Use strings to see all the strings in the `.so` file
```
# Identifies the binary type/architecture (ELF, aarch64, stripped). This tells us how to analyze it and that symbols are mostly removed.
file resources/lib/arm64-v8a/libCamera.so 

# Extracts printable strings embedded in the binary. This is how we found the hardcoded IP 192.168.4.153 and hints like udpSocket, cmdSocket, sendto.
strings resources/lib/arm64-v8a/libCamera.so

# Lists dynamic symbols (exported/linked functions). This showed JNI methods and internal function names like _Z18udpSocketEnterancePv, giving us entry points for control/UDP sockets.
nm -D resources/lib/arm64-v8a/libCamera.so

# Dumps the read‑only data section. This is how we located literal strings and fixed data like the IP address and “Bv/Bw/Bx/By” bytes used for UDP stream commands.
objdump -s -j .rodata resources/lib/arm64-v8a/libCamera.so
```
8. Let Codex/Roo etc do its magic on decompiling `resources/lib/arm64-v8a/libCamera.so` and get the [video streaming](https://github.com/arjunsk/E88_Wifi_cam_drone_control/blob/main/streamer.py) code and [take off](https://github.com/arjunsk/E88_Wifi_cam_drone_control/blob/main/send_takeoff.py) code working. For the video stream, a good inspiration was [Soulear-Web-Viewer](https://github.com/arjunsk/Soulear-Web-Viewer)
9. Now, work towards adding the full control set via GPT. 

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


Flags (legacy):
- bit0 takeoff, bit1 land, bit2 emergency, bit3 rotate, bit4 headless, bit7 calibrate


## Notes

- The WiFi_CAM Java code does not open sockets; networking happens in native libs.
- Default UDP port is usually `2228` (see `IConstants.AP_MODE_UDP_PORT`).


