from ctypes.wintypes import WORD
import requests

url = "https://fanyi.baidu.com/sug"
wd = input("请输入你要翻译的英文单词: ")
dat = {
    "kw": wd
}

proxies = {
    "http": None,
    "https": None
}
resp = requests.post(url, data = dat, proxies = proxies)

print(resp)
print(resp.json()) # 以json()形式打印 对应py中的字典
resp.close()