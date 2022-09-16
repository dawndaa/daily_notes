import requests

url = "https://movie.douban.com/j/chart/top_list"
header = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
}

# 重新封装参数
param = {
    "type": "13",
    "interval_id": "100:90",
    "action": "",
    "start": 0,
    "limit": 20
}

resp = requests.get(url, params = param, headers = header)

print(resp.json())
resp.close() # 关闭连接