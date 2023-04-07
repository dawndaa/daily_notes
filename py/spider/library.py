import requests
from fake_useragent import UserAgent

ua = UserAgent()

url = "https://webvpn.xjtu.edu.cn/https/77726476706e69737468656265737421ffe546d23f3a7c45300d8db9d6562d/openplatform/g/admin/login"
data = {
	"jcaptchaCode": "",
	"loginType": 1,
	"pwd": "OknLUS/2yGkc7bVnh/MHrQ==",
	"username": "2213611635"
}
params = {"vpn-12-o2-org.xjtu.edu.cn": ""}
headers = {
	"User-Agent": ua.random,
	"Referer": "https://webvpn.xjtu.edu.cn/https/77726476706e69737468656265737421ffe546d23f3a7c45300d8db9d6562d/openplatform/login.html",
	"Cookie": "wengine_vpn_ticketwebvpn_xjtu_edu_cn=aae2ec7b589e4cc0; show_vpn=1; show_faq=1; refresh=1",
	"Host": "webvpn.xjtu.edu.cn"
}
proxies = {'http': None, 'https': None}

resp = requests.post(url, headers = headers, data = data, proxies = proxies, params = params)
print(resp.text)
