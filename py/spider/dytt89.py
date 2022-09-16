'''
该爬虫的目的: 从电影天堂中爬取2022必看热片的 名字以及bt
第一步--获取电影天堂主页源码 从中提取出必看热片中对应影片的链接
第二步--进入子页面 从中提取出电影名称和bt
第三步--将电影名称和bt存入文件中
'''
import requests
import re
import csv

# 获取主页源代码
dytt = "https://www.dytt89.com/"
proxies = {'http': None, 'https': None}

resp = requests.get(dytt, proxies = proxies)
resp.encoding = "gb2312" # 选择网页中使用的编码方式

# print(resp.text)

# 从主页源码中提取必看热片对应的代码段
obj_1 = re.compile(r'2022必看热片.*?<ul>(?P<ul>.*?)</ul>', re.S)
ret_1 = obj_1.finditer(resp.text)

for it in ret_1:
	# print(it.group("ul").strip())
	page = it.group("ul").strip()

	# 从必看热片对应的代码段中提取出子页面的链接
	obj_2 = re.compile(r"<li><a href='(?P<href>.*?)'.*?</li>", re.S)
	ret_2 = obj_2.finditer(page)

	f = open("movie.txt", mode = "w", encoding = "utf-8")

	for it in ret_2:
		child_url = f"{dytt}{it.group('href')}"
		resp_1 = requests.get(child_url, proxies = proxies)
		resp_1.encoding = "gb2312"
		# print(resp_1.text)

		# 从子页面中提取相应电影名称和bt
		child_page = resp_1.text
		magnet_pat = re.compile(r'<td style="WORD-WRAP: break-word" bgcolor="#fdfddf">'
		r'<a href="magnet:.*?">(?P<bt>.*?)</a>', re.S)
		name_pat = re.compile(r'<div class="title_all"><h1>(?P<name>.*?)</h1></div>', re.S)

		magnet = magnet_pat.finditer(child_page)
		name = name_pat.finditer(child_page)

		for it in name:
			f.write(it.group('name').strip())
			f.write("\n")
			print(it.group('name').strip())
		for it in magnet:
			f.write(it.group('bt').strip())
			f.write("\n")
			print(it.group('bt').strip())
		print("\n")
		f.write("\n")

	f.close()