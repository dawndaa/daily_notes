import requests # 导入requests模块
import time

# wd = input("请输入你想要搜索的关键词: ")  #搜索关键词
url = "https://baike.sogou.com/v704049.htm?fromTitle=iu"
header = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"}
# 在请求中加入header中的UA 防反爬

proxies = {"http": None, "https": None}

resp = requests.get(url, headers = header, proxies = proxies) # GET方式进行请求

print(resp) # 打印响应状态 200 404 504等
print(resp.text) # 显示源代码
resp.close()
