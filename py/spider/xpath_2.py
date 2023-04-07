import requests
from lxml import etree
from fake_useragent import UserAgent
# fake包 用来随机产生ua

ua = UserAgent()
url = "https://www.taobao.com/index.php?from=top"
proxies = {"http": None, "https": None}
headers = {"User-Agent": ua.random}
resp = requests.get(url, headers = headers, proxies = proxies)
resp.encoding = 'utf-8'
print(resp.text)

resp.close()