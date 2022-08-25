#!/usr/local/bin/python3

from colorama import *
import time
import os,platform

def Oscar_Banner():
    if platform.uname()[0] == "Linux":
        os.system("clear")
    elif platform.uname()[0] == "Windows":
        os.system("cls")
    print(Fore.RED+"""

 ▒█████       ██████     ▄████▄      ▄▄▄          ██▀███   
▒██▒  ██▒   ▒██    ▒    ▒██▀ ▀█     ▒████▄       ▓██ ▒ ██▒
▒██░  ██▒   ░ ▓██▄      ▒▓█    ▄    ▒██  ▀█▄     ▓██ ░▄█ ▒
▒██   ██░     ▒   ██▒   ▒▓▓▄ ▄██▒   ░██▄▄▄▄██    ▒██▀▀█▄        
░ ████▓▒░   ▒██████▒▒   ▒ ▓███▀ ░    ▓█   ▓██▒   ░██▓ ▒██▒
░ ▒░▒░▒░    ▒ ▒▓▒ ▒ ░   ░ ░▒ ▒  ░    ▒▒   ▓▒█░   ░ ▒▓ ░▒▓░      By Aryan ...
  ░ ▒ ▒░    ░ ░▒  ░ ░     ░  ▒        ▒   ▒▒ ░     ░▒ ░ ▒░
░ ░ ░ ▒     ░  ░  ░     ░             ░   ▒        ░░   ░ 
    ░ ░           ░     ░ ░               ░  ░      ░     
                        ░                                 
            """+Style.RESET_ALL)

    
def listoption():
    time.sleep(0.1)
    print(Fore.RED+" ["+Fore.WHITE+"-"+Fore.RED+"]"+Fore.WHITE+" Choose one of the options dear \n\n")
    time.sleep(0.3)
    print(Fore.RED+" [1]"+Fore.WHITE+" Windows keylogger   "+Fore.RED+"         [2]"+Fore.WHITE+" Linux keylogger\n")
    time.sleep(0.2)
    print(Fore.RED+" [3]"+Fore.WHITE+" Help & Develper    " +Fore.RED+"          [4]"+Fore.WHITE+" Exit . . .\n")
