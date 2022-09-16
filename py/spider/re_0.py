import re

# findall(pattern, string) 找到所有匹配的内容 返回列表
lst = re.findall(r"\d+", "我是你爸爸10086, 你是我儿子10010")
print(lst)

# finditer(pattern, string) 找到所有匹配的内容 返回迭代器
it = re.finditer(r"\d+", "我是你爸爸10086, 你是我儿子10010")
for i in it:
    print(i.group())

# match(pattern, string)  找到一个匹配的从头开始的结果 返回迭代器 没找到返回none
s = re.match(r"\d+", "10086")
if s:
    print(s)
else :
    print("none!")

s1 = re.match(r"\d+", "a10086")
if s1:
    print(s1)
else: print("None!")

# search(pattern, string) 找到一个匹配的结果 返回迭代器 没找到返回none
m = re.match(r"\d+", "bbbbbb")
if m:
    print(m)
else :
    print("none!")

# compile(pattern) 预加载正则表达式 可以重复利用
# (?P<名称>pattern_1)  将匹配内容放在()中可以进行存储 
# 在前面加上?P<name> 可以通过ret.group("name")取出pattern_1所匹配的内容
obj = re.compile(r"(?P<wd1>\w+)@(\w+)")
ret1 = obj.findall("1234@123@2123@132")
print(ret1)

ret2 = obj.finditer("1234@123@2123@132")
for j in ret2:
    print(j.group())
    print(j.group("wd1"))
    print(j.group(2))

ret3 = obj.match("@23flsjd@fjsdl")
if ret3:
    print(ret3.group())
else:
    print("None!")

ret4 = obj.search("@fsjdlf@fjsl")
if ret4:
    print(ret4.group())
else:
    print("None")

text = ""