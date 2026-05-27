# Oscar Keylogger

<p align="center">
  <img src="https://img.shields.io/badge/platform-Windows-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/language-Python%20%2B%20C++-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/status-Inactive-yellow?style=for-the-badge">
</p>

> ⚠️ This project is currently inactive and hasn't been updated for 1–2 years.  
> A refreshed and improved version is planned in the future.

Oscar is a Windows-based payload generator that creates a customizable keylogging executable capable of sending captured keystrokes directly to a Telegram bot.

Built with:
- **Python** → configuration & builder
- **C++** → lightweight keylogging payload

---

# Disclaimer

This project is intended **strictly for educational purposes and authorized security testing**.

Unauthorized monitoring, keylogging, or access to systems you do not own or have permission to test is illegal and unethical.

The author assumes **no responsibility** for misuse or damages caused by this software.

---

# Why "Oscar"?

When this project started, the *Moon Knight* series had just released and Oscar Isaac was everywhere.

The name stuck.

No deep meaning. Just good timing and a cool vibe.

---

# Features

- Lightweight C++ keylogger payload
- Telegram integration for live log delivery
- Custom executable icons
  - Excel
  - PDF
  - Word
  - and more...
- Hidden console window (stealth mode)
- Easy configuration through Python interface
- Simple payload generation process

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

## 3. Install MinGW & libcurl

### Install MinGW
Download:
- https://www.mingw-w64.org/

---

### Install vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

---

### Install libcurl

```bash
./vcpkg install curl
```

Make sure both:
- `g++`
- `libcurl`

are added to your system `PATH`.

---

# Usage

## 1. Create a Telegram Bot

Use:
- `@BotFather` → to obtain your bot token
- `@userinfobot` → to get your Telegram chat ID

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

Generated executable:
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

Planned future improvements:
- Linux support
- Better stealth techniques
- Improved payload builder
- Cleaner UI
- Encryption support
- Modular architecture

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
