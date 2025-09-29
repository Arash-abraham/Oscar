#!/usr/local/bin/python3
# To do
import os
import platform
from colorama import *
import time
from modules import banner
from modules import gnt

while True:
  banner.Oscar_Banner()
  banner.listoption()
  try:
    get_option = input(Fore.LIGHTWHITE_EX+"\n Oscar > " )
    if get_option == "1":
      gnt.win_payload()
    elif get_option == "2":
      banner.Oscar_Banner()
      time.sleep(0.2)
      print(Fore.RED+" We are currently developing for Linux; at the moment, only Windows is supported.")
      input(Fore.LIGHTMAGENTA_EX+ "\n\n Back To The Menu ( Press Enter ... ) ")
    elif get_option == "3":
      banner.Oscar_Banner()
      time.sleep(0.2)
      print(Fore.LIGHTWHITE_EX+"\n Help > Directory /Ocar/README.md")
      time.sleep(0.2)
      print(Fore.RED + "\n Develper > Arash Abraham")
      time.sleep(0.2)
      print(Fore.YELLOW + "\n GitHub > https://github.com/arash-abraham")
      time.sleep(0.2)
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
