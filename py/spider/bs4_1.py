import requests
import re
import csv
from bs4 import BeautifulSoup
from concurrent.futures import ThreadPoolExecutor

f = open("../misc/price.txt", mode = "w", encoding = "utf-8")
# csvwriter = csv.writer(f)

def func(index):
    url = "http://www.xinfadi.com.cn/getPriceData.html"

    data = {
        "limit": "20",
        "current": index,
        "pubDateStartTime": "",
        "pubDateEndTime": "",
        "prodPcatid": "1186",
        "prodCatid": "",
        "prodName": ""
    }

    resp = requests.post(url, data = data)

    obj = re.compile(r'"prodName":"(?P<name>.*?)".*?"lowPrice":"(?P<low>.*?)","highPrice":"(?P<high>.*?)",'
    r'"avgPrice":"(?P<ave>.*?)","place":"(?P<place>.*?)".*?"unitInfo":"(?P<m>.*?)","pubDate":"(?P<time>.*?)".*?}', re.S)
    ret = obj.finditer(resp.text)

    for it in ret:
        # print(it.group("name"))
        # print(it.group("low"))
        # print(it.group("high"))
        # print(it.group("ave"))
        # print(it.group("place"))
        # print(it.group("m"))
        # print(it.group("time"))
        
        '''
        手动以[, , , , , ] 格式写入
        csvwriter.writerow([it.group("name"), it.group("low"), it.group("high"), it.group("ave") , it.group("place"), it.group("m"), it.group("time")])
        '''

        # 使用groupdict() 返回字典 直接向csv文件中写入字典的value
        dic = it.groupdict()
        f.write(dic.values())

    resp.close()
    print(f"{index}over!!!")

if __name__ == '__main__':
    # 创建线程数为50的线程池
    with ThreadPoolExecutor(50) as t:
        for i in range(1, 1000):
            t.submit(func, index = i)
    f.close()
    print("All Over!!!")