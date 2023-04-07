from urllib.request import urlopen

url = "https://investmentpolicy.unctad.org/investment-dispute-settlement/cases/1219/addiko-bank-v-slovenia"
resp = urlopen(url)

with open("mybaidu.html", mode = "w", encoding = "utf-8") as f:
	f.write(resp.read().decode("utf-8"))
print("over!")