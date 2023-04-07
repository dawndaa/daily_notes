import requests
import re
import csv

index = 0
add = 25
f = open("data.csv", mode = "w", encoding = 'utf-8') 
# 以写入模式 打开(创建)一个名为 data.csv 的文件 并设置编码方式为utf-8
csvwriter = csv.writer(f) 
# 返回一个csv的writer对象 用于后续向文件中写入数据

while index < 250:
    url = f"https://movie.douban.com/top250?start={index}&filter="
    proxies = { "http": None, "https": None}
    header = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
    }

    page = requests.get(url, headers = header, proxies = proxies)
    # print(page.text)

    pattern = re.compile(r'<li>.*?<span class="title">(?P<name>.*?)</span>.*?<br>(?P<year>.*?)&nbsp'
                        r'.*?<span class="rating_num" property="v:average">(?P<score>.*?)</span>', re.S)
    # 此处compile中要加入re.S参数 让.能够匹配换行符

    ret = pattern.finditer(page.text)
    # print(ret)

    for it in ret:
        # print(it.group())
        # print(it.group("name"))
        # print(it.group("year").strip())
        # print(it.group("score"))
        # print("\n")

        dic = it.groupdict() # 将it.group() 以dict即字典的形式返回
        dic['year'] = dic['year'].strip()

        #  {'name': '肖申克的救赎', 'year': '1994', 'score': '9.7'}
        # print(dic), print("\n")

        csvwriter.writerow(dic.values())
        # writerrow()一次写入一行 wirterrows()一次写入多行

    page.close()
    index += add