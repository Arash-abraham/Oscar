# Oscar Keylogger

> **Project status:** Inactive for about 1-2 years – will be revived and updated soon.

A tool to generate a customizable keylogger payload for Windows. It captures keystrokes and sends them discreetly to your Telegram bot.

**For educational purposes or authorized security testing only. Unauthorized keylogging is illegal and unethical.**

---

## Why the name "Oscar"

When I started this project, the Moon Knight series had just come out, featuring Oscar Isaac as Marc Spector. The name stuck. No hidden meaning - just a good show from that time.

And if you want to know the vibe when this code was written:

https://i.imgur.com/uAcYBFj.mp4

(Search "Moon Knight gif" if the link doesn't work.)

---

## Features

- Python interface for configuration, C++ for keylogging – easy setup, efficient logging
- Sends logs to your Telegram bot – keystrokes + system info
- Custom icons – mimic Excel, PDF, Word, etc.
- Stealth mode – console window is hidden

---

## Prerequisites

- Windows OS only (for now)
- Python 3.8 or higher
- Git
- MinGW (g++)
- libcurl
- Python dependencies (see requirements.txt)

---

## Installation

1. Clone the repository:
"""
git clone https://github.com/Arash-abraham/Oscar.git
cd Oscar
"""

2. Install Python dependencies:
"""
pip install -r requirements.txt
"""

3. Install MinGW and libcurl:
   - Download MinGW from mingw-w64.org
   - Install vcpkg:
"""
git clone https://github.com/microsoft/vcpkg.git
"""
   - Install libcurl:
"""
./vcpkg install curl
"""
   - Add MinGW and libcurl to your system PATH

**Note:** Linux support is under development.

---

## Usage

1. Create a Telegram bot:
   - Use @BotFather on Telegram to get your Bot Token
   - Use @userinfobot to get your Chat ID

2. Run the tool:
"""
python Oscar.py
"""
   - Enter payload name (e.g., Oscar)
   - Input Bot Token and Chat ID
   - Select an icon (Excel, PDF, etc.)
   - Executable will be generated in `dist/<payload_name>.exe`

3. Run the generated payload:
"""
./dist/<payload_name>.exe
"""

---

## Project Structure

Oscar/
├── CPP-Payload/
│   └── keylog.cpp
├── icon/
│   ├── excel.ico
│   ├── pdf.ico
│   ├── word.ico
│   └── ...
├── modules/
│   ├── banner.py
│   └── gnt.py
├── Oscar.py
├── README.md
└── requirements.txt

---

## Security and Ethics

- Use only with explicit permission
- Never expose your Telegram Bot Token
- Comply with local laws

---

## Troubleshooting

- Compilation errors: Make sure g++ and libcurl are installed and in PATH.
  Check with:
"""
g++ --version
pkg-config --modversion libcurl
"""
- Icon not applied: Verify icon files exist in `icon/` directory
- Telegram not sending logs: Double-check Bot Token and Chat ID

---

## Contact

arashebi777@gmail.com

---

*Hack away.*

