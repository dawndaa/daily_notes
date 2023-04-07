from urllib.request import urlopen

url = "https://leetcode.cn/"
resp = urlopen(url)

with open("leetcode.html", mode = "w", encoding = "utf-8") as f:
	f.write(resp.read().decode("utf-8"))
print("Ok!")