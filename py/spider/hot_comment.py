import requests
from fake_useragent import UserAgent

ua = UserAgent()
url = "https://music.163.com/weapi/comment/resource/comments/get"
dat = {
	"params": "z1Wsn0NrqCIgXWxuXC0hv0O8O/MgGfMi/U8gweYRrZEP4S+Llu8KTkAKwPVNPa6sP8I00PdRh/bdBZoaRoBzLnyWu6pdRrMf1mYwmbOyp8/pHwUFdOfFkrTAW7UYQMgfvoOE/TDISSsttmhefWbq0rK3cb76ugsDftzTU27os0i9Y2qcvmNr7qD+bxbWI82cr2avsEyK7jVGf8qgOfJSRuyg1Jr7sEcppDXWRv9jAIZWQ+fsNguBt+02whT00NWlNBxS/BW2sLiLn8/cvcIsQRpUpWxWahFaTUjy9k6MM3I=",
	"encSecKey": "7bbaa334b134a7a1d53ad41c82665d9f4e13de6582eb624980d1e6d2b12142078b1c3e98a0f3329ea8a297502e1d56f788e6109e2a043434ff454973e27b698364fccd651ab7c840ef91667d8186be18371e2740b9d4477b896f66e55ccea87f6181ef8a01345fd19158706888cec0f6572a12e0e5b1c42b707c72aef2fdad93"
}
headers = {
	"User-Agent": ua.random
}
proxies = {'http': None, 'https': None}

resp = requests.post(url, headers = headers, proxies = proxies, data = dat)
print(resp.json())