import requests
import time
from bs4 import BeautifulSoup
from fake_useragent import UserAgent

# 拿到网页源代码
url = "http://m.youmeitu.com/"
ua = UserAgent()
headers = {"User-Agent": ua.random}
proxies = {'http': None, 'htpps': None}
resp = requests.get(url, headers = headers, proxies = proxies, verify = False)
resp.encoding = "utf-8"
# print(resp.text)
resp.close()

# 生成bs对象 并拿到子页面网址
page = BeautifulSoup(resp.text, "html.parser") # 指定解析器为html.parser
uls = page.find_all("ul", attrs = {"class": "ChannelPicList"})
for ul in uls:
	alist = ul.find_all("a")
	for a in alist:
		href = a.get("href")
		child_url = url + href.strip("/")

		# 连接子网页并拿到图片地址
		child_resp = requests.get(child_url)
		child_page = BeautifulSoup(child_resp.text, "html.parser")
		p = child_page.find("p", attrs = {"align": "center"})
		src = p.img.get("src")
		name = src.split('/')[-1]
		print(src)

		# 连接图片地址并下载
		proxies = {"http": None, "https": None}
		headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"}
		
		ret = requests.get(src, proxies = proxies, headers = headers)
		# 相对文件路径 ..为父文件夹 .为本文件夹
		with open(name, mode = "wb") as f:
			f.write(ret.content)

		time.sleep(1)
		# print(f"{name} over!")
		ret.close()
		child_resp.close()

print("over!")
resp.close()