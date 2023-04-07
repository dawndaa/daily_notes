import requests
from bs4 import BeautifulSoup

# 拿到页面源代码
proxies = {"http": None, "https": None}
url = "https://www.dytt89.com/"
resp = requests.get(url, proxies = proxies)
resp.encoding = "gb2312"

# print(resp.text)

# 解析数据
# 1. 将数据交给BeautifulSoup 生成bs对象
page = BeautifulSoup(resp.text, "html.parser") # 指定语法解析器为 html.parser

# 2. 从bs对象中查找数据  找一个 -- find(标签, 属性=值)  找全部 -- find_all(标签, 属性=值)
divs = page.find_all("div", class_ = "co_content222") # class是py中的关键字 所以bs4用class_来代替class
# page.find("table", attrs = {"class": "hq_table"})

# 拿到所有的 class = "co_content222"的div 返回的是一个列表
# print(div)

for div in divs:
	lis = div.find_all("li")
	for li in lis:
		print(li.a.get("title"))  # tag.get("attr_name") 使用get拿到标签中属性的值
		print(li.a) # li.a 拿到li标签中的a标签
		print(li.text) # tag.text 代表该标签标记的内容 如<p>你好</p> p.text = 你好