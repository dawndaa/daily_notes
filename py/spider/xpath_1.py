from lxml import etree
import requests

url = "https://dawn_512.gitee.io/birthday/"
proxies = {"http": None, "https": None}
headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"}
resp = requests.get(url, headers = headers, proxies = proxies)
resp.encoding = "utf-8"
print(resp.text)

tree = etree.HTML(resp.text) #将html文件丢给etree 获取xpath对象
ret = tree.xpath("/html/body/span/text()")  # ['生日快乐啊！宝']
# 层级关系 第一个/是根节点  text()是获取被标签标记的内容
ret = tree.xpath("/html/body//span/text()") # ['生日快乐啊！宝', '所爱隔山海', '山海亦可平']
# // 代表已匹配节点下任意路径 
ret = tree.xpath("/html/body/*/span/text()") # ['所爱隔山海', '山海亦可平']
# * 代表任意一个节点
ret = tree.xpath("//span[@class = 'outline'][1]/text()") # ['所爱隔山海']
# [@attr = value] 利用@可以指定属性的值  [1]利用下标可以从列表中提取出单独元素
ret = tree.xpath("//span/@class") # ['outline', 'outline']
# @attr 可以拿到节点的属性值

print(ret)