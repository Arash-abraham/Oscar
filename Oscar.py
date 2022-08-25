#!/usr/local/bin/python3

import os
import platform
from colorama import *
import time
from modules import banner
from modules import gntrsh
from modules import gntwin

while True:
    banner.Oscar_Banner()
    banner.listoption()

    try:
        get_option = input(Fore.LIGHTWHITE_EX+"\n Oscar > " )

        if get_option == "1":
              if platform.uname()[0] == "Windows":
                    gntwin.win_payload()
              elif platform.uname()[0] == "Linux":
                    print(Fore.RED+" Sorry, but this feature is for Windows")
                    input(Fore.LIGHTMAGENTA_EX+ "\n\nBack To The Menu ( Press Enter ... ) ")
        elif get_option == "2":
          gntrsh.sh_payload()
        elif get_option == "3":
          banner.Oscar_Banner()
          print(Fore.LIGHTWHITE_EX+"\n Help > Directory /Ocar/README.md")
          print(Fore.RED + "\n Develper > Aryan")
          print(Fore.YELLOW + "\n GitHub > https://github.com/aryan-abraham")
          input(Fore.LIGHTMAGENTA_EX+ "\n\n Back To The Menu ( Press Enter ... ) ")
        elif get_option == "4":
          print(Fore.RED+"\n\n Good By Bro ... "+Style.RESET_ALL)
          exit()
        elif get_option != "1" or "2" or "3" or "4":
            banner.Oscar_Banner()
            print(Fore.LIGHTCYAN_EX+" Please select one of the desired options"+Style.RESET_ALL)
            input(Fore.LIGHTMAGENTA_EX+ "\n Back To The Menu ( Press Enter ... ) ")

    except KeyboardInterrupt:
        print(Fore.RED+"\n\n Good By Bro ... "+Style.RESET_ALL)
        exit()
