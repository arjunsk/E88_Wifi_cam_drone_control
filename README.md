# E88 WiFi drone control (reverse-engineered from WiFi_CAM + VSCode Codex)

This is a minimal UDP sender based on `sources/com/tzh/wifi/wificam/model/base/BaseCmd.java` for [E88 drone](https://share.temu.com/gd16GrwHmTC).
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
5. [Skipped] You can also use `sudo tcpdump -i en0 -nn udp` to see UDP connections as mentioned [here](https://github.com/SeanPesce/Suear-Web-Viewer/issues/9), but not sure if it's very helpful.
6. [Skipped] You can also take a stab at looking at `Logcat` by attaching your Android phone via USB. I didn't have Android Studio installed on my Mac.
7. [Skipped] The core code that talks to the drone is in the `.so` C++ compiled binary code. You could use [Ghidra](https://youtube.com/shorts/4DpV0zdJEk0?si=OEvr-Z2v8rl0pbHy) to take a look at that.
8. [Skipped] Use strings to see all the strings in the `.so` file
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
8. Let Codex/Roo etc do its magic on decompiling `resources/lib/arm64-v8a/libCamera.so` and get the [video streaming](https://github.com/arjunsk/E88_Wifi_cam_drone_control/blob/main/streamer.py) code and [take off](https://github.com/arjunsk/E88_Wifi_cam_drone_control/blob/main/send_takeoff.py) code working. For the video stream, a good inspiration was [Soulear-Web-Viewer](https://github.com/SeanPesce/Suear-Web-Viewer)
9. Now, work towards adding the full control set via GPT. 

## Packet formats

Legacy (8 bytes):
- [0] 0x66 <--- ok
- [1] roll (0..255, 128 = center) <--- left and right
- [2] pitch (0..255, 128 = center) <--- forward and backward
- [3] throttle (0..255, 0 = low) <--  up and down
- [4] yaw (0..255, 128 = center) <--- rotational left and right, i.e., spin
- [5] flags <--- ok
- [6] checksum = XOR bytes [1..5], sanitized to avoid 0x66/0x99 <--- ok
- [7] 0x99 <--- ok


Flags (legacy):
- bit0 takeoff, bit1 land, bit2 emergency, bit3 rotate, bit4 headless, bit7 calibrate

## Notes

- The WiFi_CAM Java code does not open sockets; networking happens in native libs.
- Default UDP port is usually `2228` (see `IConstants.AP_MODE_UDP_PORT`).


## [Learning] How to sniff the commands 
- WiFi sniffing can be done via Wireshark on android phone. (Well, this one I tried and failed)
- Log streaming via Android Studio (well, it works only if the developer writes log statements to print the UDP commands or something)
- RF sniffing can be done via [these](https://tobiabocchi.me/posts/rf-hacking-101/) (this is another way to confirm what RC is sending to RF MCU). Drone RF is 2.5GHz. If it was small, we could may be use Flipper Zero to mess around.
- Signal sniffing can be done via a Logic Analyzer. (will be used when I am going to switch from the existing WiFi module to the ESP32 CAM module, to validate what the previous WiFi chip used to send to the RF MCU.)
- Or decompile the app itself to get the UDP commands (I did that for controling drone from my laptop)



## [Learning] AI notion
```
AI
├── Symbolic AI (rules, logic)
├── Classical ML
│   ├── Linear models
├── Neural Networks
│   ├── Perceptron
│   ├── ANN
│   ├── CNN
│   └── Transformers
│       └── LLMs
└── Control Systems
    └── State machines

```
- classic ML algos --> clasification etc
- faster control loop ---> OpenCV / CNN
- control loop --> Waymo driver --> [Perceptron](https://www.slideshare.net/slideshow/ann-based-browser-game/238966386?from_search=3#1) / ANN / CNN
- planning/reasoning --> ChatGPT --> LLM 

<details>
<summary>LLM example</summary>

```
embedder = SentenceTransformer("sentence-transformers/all-MiniLM-L6-v2")

def hf_generate(prompt: str, max_new_tokens=256, temperature=0.2) -> str:
....

def vectordb_search(query_vector, top_k=5):
....

def answer_question(question: str, top_k=5) -> dict:
    q_vec = embedder.encode(question, normalize_embeddings=True)

    hits = vectordb_search(q_vec, top_k=top_k)
    contexts = []
    for i, h in enumerate(hits, start=1):
        contexts.append(f"[{i}] {h['text']} (score={h.get('score','?')}, meta={h.get('meta',{})})")

    prompt = f"""You are a helpful assistant. Answer ONLY using the provided context. If the answer isn't in the context, say "I don't know."

Question:
{question}

Context:
{chr(10).join(contexts)}

Answer:
"""
    ans = hf_generate(prompt)
    return {"answer": ans, "sources": hits}


```

</details>



- So LLM Language mode is a giant [ANN](https://www.slideshare.net/slideshow/ann-based-browser-game/238966386?from_search=3#1) trained over large texts to predict the next word with probability.


<details>
<summary>LLM flow</summary>

```

User Question
      +
Retrieved Paragraphs (Vector DB)
              |
              v
+------------------------------------------------+
|                 TOKENIZER                      |
|  text  →  tokens (numbers)                     |
+------------------------------------------------+
              |
              v
+------------------------------------------------+
|         EMBEDDINGS + POSITION                  |
|  tokens → vectors + order (1st, 2nd, ...)      |
+------------------------------------------------+
              |
              v
+------------------------------------------------+
|          TRANSFORMER (repeated layers)         |
|                                                |
|   +----------------------------------------+   |
|   |  SELF-ATTENTION  ("highlighting")      |   |
|   |                                        |   |
|   |  - each token looks at ALL tokens      |   |
|   |  - gives them importance weights       |   |
|   |  - important words = strong signal     |   |
|   |                                        |   |
|   +----------------------------------------+   |
|                        |                       |
|                        v                       |
|   +----------------------------------------+   |
|   |  SMALL ANN / MLP ("thinking")           |   |
|   |                                        |   |
|   |  - mixes highlighted information       |   |
|   |  - builds meaning / reasoning          |   |
|   |                                        |   |
|   +----------------------------------------+   |
|                                                |
|   (this block runs many times)                 |
+------------------------------------------------+
              |
              v
+------------------------------------------------+
|      VOCABULARY SCORES (LOGITS)                |
|  one score for each possible token/word        |
+------------------------------------------------+
              |
              v
+------------------------------------------------+
|            SAMPLER                             |
|  - softmax                                    |
|  - temperature / top-k / top-p                |
|  - pick ONE next token                        |
+------------------------------------------------+
              |
              v
          NEXT TOKEN
              |
              v
   append token to input text
              |
              v
        (entire process repeats)

```

</details>

## [Learning] How does GPS work?

- https://www.youtube.com/shorts/1BcIhVtG-dM Relative locations, 24 satellites around the Earth
- https://www.youtube.com/shorts/udPqVzqmFDM Needs 4 satellites
- Can GPS get overloaded?
```
No, a GPS satellite itself doesn't get "overloaded" by the number of users because it's a one-way broadcast system, sending signals to potentially unlimited receivers, like a radio station. However, the GPS receivers on Earth can get overloaded by strong local interference (jamming/spoofing) or space weather (solar storms), which disrupts the weak satellite signals, making them unable to determine location accurately. 
```

## [Learning] Chip 
- [SoC, MCU](https://softwareg.com.au/en-us/blogs/computer-hardware/system-on-a-chip-vs-cpu?srsltid=AfmBOopsKpKUXJ2lTY9hJKqLc0toNvpJuVXqRMyYD2tS-8ujjGWY2WAS)
<img width="1280" height="720" alt="image" src="https://github.com/user-attachments/assets/1ba67adb-db53-4efd-9d71-746d409bd08d" />

- Servo vs Stepper Motor: https://youtube.com/shorts/rift8UbrAyQ?si=u5dFD8YJnDkoDQKx
