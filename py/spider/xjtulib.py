import requests
from fake_useragent import UserAgent
from time import *

def get_connect():
    ua = UserAgent()
    url = "http://10.6.18.5:802/include/auth_action.php"
    headers = {
        "User-Agent": ua.random
    }
    proxies = {'http': None, 'https': None}
    data = {
        "action": "login",
        "username": "2213611635@xjtulib",
        "password": "030131",
        "ac_id": "1",
        "user_ip": "",
        "nas_ip": "",
        "user_mac": "",
        "save_me": "0",
        "ajax": "1"
    }

    resp = requests.post(url, data = data, headers = headers, proxies = proxies)
    if resp.headers.get('set-cookie') == None:
        print("error!")
        sleep(1)
        get_connect()
    else:
        print("success")

if __name__ == '__main__':
    get_connect()