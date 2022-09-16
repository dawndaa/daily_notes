import requests
from fake_useragent import UserAgent

url = "https://h5.17k.com/ck/user/login"
ua = UserAgent()
headers = {"User-Agent": ua.random}
data = {
	"loginName": "18879575998",
	"password": "xiao0131.",
	"appKey": "1351550300"
}
proxies = {'http': 'http://183.141.169.125', 'https': None}

# 建立一个会话
session = requests.session()
resp = session.post(url, headers = headers, proxies = proxies, data = data)
resp.encoding = 'utf-8'
print(resp.status_code)
print(resp.text)

# 拿到书架数据
bookshelf_url = "https://user.17k.com/ck/author/shelf?platform=4&appKey=1351550300"
bookshelf = session.get(bookshelf_url, headers = headers, proxies = proxies)
print(bookshelf.json()['data'])