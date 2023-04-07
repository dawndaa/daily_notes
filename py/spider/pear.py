import requests
import re
from fake_useragent import UserAgent
ua = UserAgent()

for i in range(41):
	f_url = "https://www.pearvideo.com/category_loading.jsp"
	index = 0
	f_params = {
		"reqType": "30",
		"categoryId": "15858472",
		"hotContIds": "1718968,1739892,1717669,1717724,1689714,1717529",
		"start": index,
		"mrd": "0.0035806566991452016"
	}
	f_headers = {
		"User-Agent": ua.random
	}
	p = {'http': None, 'https': None}
	f_resp = requests.get(f_url, params = f_params, headers = f_headers, proxies = p)
	f_page = f_resp.text

	f_obj = re.compile(r'<div class="vervideo-bd">.*?<a href="(?P<href>.*?)" class', re.S)
	hrefs = f_obj.finditer(f_page)

	for it in hrefs:
		# 准备参数
		re_url = "https://www.pearvideo.com/" + it.group('href')
		print(re_url)
		url = "https://www.pearvideo.com/videoStatus.jsp"
		cont_id = re_url.split('_')[-1]
		headers = {
			"User-Agent": ua.random,
			"Referer": re_url
		}
		params = {
			"contId": cont_id,
			"mrd": "0.5370541497748773"
		}
		proxies = {'http': None, 'https': None}

		# 连接到视频网站 并获取视频链接
		resp = requests.get(url, headers = headers, params = params, proxies = proxies)
		dic = resp.json()
		system_time = dic['systemTime']
		src_url = dic['videoInfo']['videos']['srcUrl'].replace(system_time, f"cont-{cont_id}")

		# 下载视频
		ret = requests.get(src_url, headers = headers, params = params, proxies = proxies)
		with open(f"../videos/{cont_id}.mp4", mode = 'wb') as f:
			f.write(ret.content)

		# 关闭连接
		resp.close()
		ret.close()
	f_resp.close()