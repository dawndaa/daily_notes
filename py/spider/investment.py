from lxml import etree
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor
import requests
import pandas as pd
import csv

def get_data(id):
    url = "https://investmentpolicy.unctad.org/investment-dispute-settlement/cases/" + str(id) + "/addiko-bank-v-slovenia"
    proxies = {"http": None, "https": None}
    headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"}
    resp = requests.get(url, headers = headers, proxies = proxies)
    resp.encoding = "utf-8"

    tree = etree.HTML(resp.text) #将html文件丢给etree 获取xpath对象
    ret = tree.xpath("//div[@class = 'page-content']//div[@class = 'item']")
    #//*[@id="main-container"]/div/div/div[2]/div[3]/div/div[10]/div[1]/h4/a/span[2]
    # //*[@id="main-container"]/div/div/div[2]/div[3]/div/div[7]
    # //*[@id="main-container"]/div/div/div[2]/div[3]/div/div[7]/div[1]/h4/a/span[2]
    # //*[@id="rules-institution-content"]/div[1]/label/text()
    f = open("data.csv", mode = "a", encoding = "utf-8")
    csvwriter = csv.writer(f)
    # f.write(str(id) * 20)
    # f.write("\n")
    
    lines = []
    for it in ret:
        # name = it.xpath("./div[1]/h4/a/span[2]/text()")[0]
        # f.write(f"{name}: \n")
        datas = it.xpath("./div[2]/div")
        block = ""
        for data in datas:
            class_name = data.xpath("./@class")
            if (class_name[0] == 'labeled-data'): 
                label = data.xpath("./label/text()")[0].strip()
                content = data.xpath("./div/text()")[0].strip()
                block += f"{label}: {content}\n"
                # f.write(f"\t{label}: {content}\n")
            else: 
                aes = data.xpath("./a")
                if aes == []:
                    div_content = data.xpath("./text()")[0].strip()
                    block += div_content
                else:
                    for a in aes:
                        a_content = a.xpath("./text()")[0].strip()
                        block += f"{a_content}\n"
                        # f.write(f"\t{a_content}\n")
        lines.append(block)
        # f.write("\n")
    # print(lines)
    csvwriter.writerow(lines)
    # f.write("\n\n")
    print(f"{id}over")
    
def csv2xlsx():
    # Reading the csv file
    df_new = pd.read_csv('data.csv')
    
    # saving xlsx file
    GFG = pd.ExcelWriter('inves_data.xlsx')
    df_new.to_excel(GFG, index=False)
    
    GFG.save()

if __name__ == '__main__':
    with ThreadPoolExecutor(5) as t:
        for i in range(1, 1240):
            t.submit(get_data, id = i)
    csv2xlsx()
    print("over!")