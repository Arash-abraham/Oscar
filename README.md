<p align="center">
  <img src="https://i.imgur.com/uAcYBFj.gif" width="850">
</p>

<h1 align="center">Oscar Keylogger</h1>

<p align="center">
  <img src="https://img.shields.io/badge/platform-Windows-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/language-Python%20%2B%20C++-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/status-Inactive-yellow?style=for-the-badge">
  <img src="https://img.shields.io/badge/version-1.0-darkred?style=for-the-badge">
</p>

<p align="center">
  <i>"There's chaos in you."</i>
</p>

---

> ⚠️ This project has been inactive for around 1–2 years.  
> A cleaner and improved version is planned for the future.

Oscar is a customizable Windows payload generator capable of creating a lightweight keylogging executable that sends captured keystrokes directly to your Telegram bot.

Built with:
- **Python** → Builder & configuration interface
- **C++** → Lightweight payload

---

# Disclaimer

This project is intended strictly for:
- Educational purposes
- Authorized security testing
- Malware analysis research

Unauthorized keylogging or monitoring of systems without explicit permission is illegal and unethical.

The author assumes no responsibility for misuse or damages caused by this software.

---

# Why "Oscar"?

When this project was first written, the *Moon Knight* series had just dropped.

Oscar Isaac was everywhere.

The name stayed.

No hidden meaning. Just a cool vibe from that era.

---

# Features

- Lightweight C++ payload
- Telegram-based log delivery
- Custom executable icons
  - Excel
  - PDF
  - Word
  - and more...
- Hidden console window
- Easy payload generation
- Python-powered configuration interface
- Minimal and simple workflow

---

# Requirements

## Supported OS
- Windows

## Dependencies

- Python 3.8+
- Git
- MinGW (g++)
- libcurl
- Python packages from `requirements.txt`

---

# Installation

## 1. Clone the repository

```bash
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
```

---

## 2. Install Python dependencies

```bash
pip install -r requirements.txt
```

---

## 3. Install MinGW

Download and install:
https://www.mingw-w64.org/

Make sure `g++` is added to PATH.

Verify installation:

```bash
g++ --version
```

---

## 4. Install libcurl

Clone vcpkg:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

Install curl:

```bash
./vcpkg install curl
```

Verify:

```bash
pkg-config --modversion libcurl
```

---

# Usage

## 1. Create a Telegram Bot

Use:
- `@BotFather` → Get your Bot Token
- `@userinfobot` → Get your Chat ID

---

## 2. Launch Oscar

```bash
python Oscar.py
```

You will be prompted to:
- Enter payload name
- Enter Telegram Bot Token
- Enter Chat ID
- Select executable icon

Generated file:

```bash
dist/<payload_name>.exe
```

---

## 3. Run the Payload

```bash
./dist/<payload_name>.exe
```

---

# Project Structure

```bash
Oscar/
│
├── CPP-Payload/
│   └── keylog.cpp
│
├── icon/
│   ├── excel.ico
│   ├── pdf.ico
│   ├── word.ico
│   └── ...
│
├── modules/
│   ├── banner.py
│   └── gnt.py
│
├── Oscar.py
├── README.md
└── requirements.txt
```

---

# Troubleshooting

## g++ not detected

```bash
g++ --version
```

---

## libcurl issues

```bash
pkg-config --modversion libcurl
```

---

## Icon not applied

Make sure icon files exist inside the `icon/` directory.

---

## Telegram logs not sending

Verify:
- Bot Token
- Chat ID
- Internet connection

---

# Roadmap

Planned future updates:

- Linux support
- Better stealth techniques
- Cleaner UI
- Payload encryption
- Modular architecture
- Builder improvements

---

# Security Notes

- Never expose your Telegram Bot Token
- Use only in authorized environments
- Respect local laws and regulations

---

# Contact

📧 arashebi777@gmail.com

---

<p align="center">
  <i>Hack responsibly.</i>
</p>
