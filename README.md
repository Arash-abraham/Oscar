---
## Oscar Keylogger 🕵️‍♂️

A powerful tool to generate a customizable keylogger payload for Windows. It captures keystrokes and sends them discreetly to your Telegram bot.
**⚠Warning**: This tool is for educational purposes or authorized security testing only. Unauthorized keylogging is illegal and unethical.

---
## Features 🔥
* **Python interface for configuration, C++ for efficient keylogging**: Uses Python for easy setup and C++ for optimal keylogging performance.
* **Sends logs to your Telegram bot**: All keystrokes and system information are sent directly to your Telegram bot.
* **Custom icons**: You can change the executable's icon to mimic popular files like Excel, PDF, Word, etc., to make the tool less conspicuous.
* **Stealth mode**: The keylogger operates completely hidden by concealing the console window.
* **Logs system info**: Captures and sends information such as username and operating system version.

---
## Prerequisites 🛠️
* **Windows OS**: This tool currently supports Windows operating systems only.
* **Python 3.8 or higher**: Required to run the Python scripts.
* **Git**: For cloning the repository.
* **MinGW (g++)**: For compiling the C++ code.
* **libcurl**: For communicating with the Telegram API.
* **Python dependencies**: Listed in `requirements.txt`.

---
## Installation ⚙️
1.  **Clone the repository**:
    ```bash
    git clone [https://github.com/Arash-abraham/Oscar.git](https://github.com/Arash-abraham/Oscar.git)
    cd Oscar
    ```
2.  **Install Python dependencies**:
    ```bash
    pip install -r requirements.txt
    ```
3.  **Install MinGW and libcurl**:
    * **Download MinGW**: Get it from [https://www.mingw-w64.org/downloads/](https://www.mingw-w64.org/downloads/).
    * **Install vcpkg**:
        ```bash
        git clone [https://github.com/microsoft/vcpkg.git](https://github.com/microsoft/vcpkg.git)
        ```
    * **Install libcurl**:
        ```bash
        ./vcpkg install curl
        ```
    * **Add MinGW and libcurl to your system PATH**: This step is crucial to ensure your system can access the `g++` compiler and `libcurl` library.

**Note**: Linux support is under development. Currently, only Windows is supported.

---
## Usage 🚀
1.  **Create a Telegram bot**:
    * Use `@BotFather` on Telegram to create a new bot and obtain your **Bot Token**.
    * Use `@userinfobot` to get your **Chat ID**.

2.  **Run the tool**:
    ```bash
    python3 Oscar.py
    ```
    * **Enter the payload name** (e.g., `Oscar`).
    * **Input your Bot Token and Chat ID**.
    * **Select an icon** (Excel, PDF, etc.).
    * The executable will be generated in `dist/<payload_name>.exe`.

3.  **Run the generated payload**:
    ```bash
    ./dist/<payload_name>.exe
    ```

---
## Project Structure 📁
    Oscar/
    ├── CPP-Payload/
    │   └── keylog.cpp          # C++ code for keylogging
    ├── icon/
    │   ├── excel.ico           # Custom icons
    │   ├── pdf.ico
    │   ├── word.ico
    │   └── ...
    ├── modules/
    │   ├── banner.py           # Module for banner display
    │   └── gnt.py              # Internal modules
    ├── Oscar.py                # Main Python script
    ├── README.md               # Project README file
    └── requirements.txt        # Python dependencies
    
---
## Contributing 🤝
To contribute to the project:
1.  **Fork the repository**:
    ```bash
    git fork [https://github.com/Arash-abraham/Oscar.git](https://github.com/Arash-abraham/Oscar.git)
    ```
2.  **Create a feature branch**:
    ```bash
    git checkout -b feature/your-feature
    ```
3.  **Commit your changes**:
    ```bash
    git commit -m "Add your feature"
    ```
4.  **Push to your branch**:
    ```bash
    git push origin feature/your-feature
    ```
5.  **Open a Pull Request on GitHub**.

---
## Security and Ethics ⚠️
* **Use only with explicit permission**: This tool should only be used within legal frameworks and with full authorization.
* **Never expose your Telegram Bot Token**: Your bot token is confidential and should not be shared.
* **Comply with local laws and regulations**: You are responsible for using this tool in accordance with local laws.

---
## Troubleshooting 🔧
* **Compilation errors**:
    * Ensure `g++` and `libcurl` are correctly installed and in your system's PATH.
    * Check: `g++ --version`
    * Check: `pkg-config --modversion libcurl`
* **Icon not applied**:
    * Verify that the icon files exist in the `icon/` directory.
* **Telegram not sending logs**:
    * Double-check your Bot Token and Chat ID for accuracy.

---
## Roadmap 🗺️
* **Add Linux support with X11 keylogging**.
* **Implement log encryption**.
* **Add a Graphical User Interface (GUI) for configuration**.

---
## License 📄
This project is released under the MIT License. See `LICENSE` for details.

---
## Contact 📧
Arash Abraham
Hack away!
