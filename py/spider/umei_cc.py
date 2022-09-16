import requests
from fake_useragent import UserAgent
import re
from concurrent.futures import ThreadPoolExecutor
import time

ua = UserAgent()
proxies = {'http': None, 'https': None}
pre_url = "https://www.umei.cc"
t1 = time.time()

def get_html(url):
	headers = {
		"user-agent": ua.random
	}
	obj = re.compile(r'<section class="img-content">.*?<a href="(?P<href>.*?)">'
		r'<img.*?src="(?P<src>.*?)"', re.S)

	resp = requests.get(url, headers = headers, proxies = proxies)
	resp.encoding = 'utf-8'
	ret = obj.finditer(resp.text)

	for it in ret:
		print(it.group('src'))
		get_img(it.group('src'))
		get_html(pre_url + it.group('href'))
		
	resp.close()

def get_img(src):
	headers = {
		"user-agent": ua.random
	}
	name = src.split('/')[-1]
	
	print(src)
	# s = requests.session()
	# s.keep_alive = False
	resp = requests.get(src, headers = headers, proxies = proxies)

	f =  open(f"../imgs/{name}", mode = 'wb')
	f.write(resp.content)

	f.close()
	resp.close()
	print(f"{name}over!")

def main():
	urls = [
		"https://www.umei.cc/meinvtupian/xingganmeinv/246410.htm",
		"https://www.umei.cc/meinvtupian/meinvxiezhen/246997.htm",
		"https://www.umei.cc/meinvtupian/meinvzipai/241633.htm",
		"https://www.umei.cc/meinvtupian/meinvxiezhen/246971.htm",
		"https://www.umei.cc/meinvtupian/siwameinv/235686.htm",
		"https://www.umei.cc/meinvtupian/rentiyishu/203062.htm",
	]


	for i in urls:
		get_html(i)

if __name__ == '__main__':
	main()