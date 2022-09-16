import requests
from fake_useragent import UserAgent
from selenium import webdriver
from time import *

with open('info.txt') as f:
    account = f.readline().strip()
    password = f.readline().strip()

browser = webdriver.Chrome()
url = "http://rg.lib.xjtu.edu.cn:8086/"
browser.get(url)

acc = browser.find_element('xpath', '//input[@type = "text"]')
pwd = browser.find_element('xpath', '//input[@type = "password"]')
login = browser.find_element('id', 'account_login')

acc.send_keys(account)
pwd.send_keys(password)
login.click()
sleep(1)

seat = browser.find_element('xpath', '/html/body/div[3]/div/div[1]/div[1]/div[1]/h1/span/a')
seat.click()

north2 = browser.find_element('xpath', '/html/body/div[2]/center/div/div/div/div/div[4]/a[@id = "north2elian"]')
north2.click()

seats = browser.find_elements('xpath', '/html/body/div[2]/div/div/div/*/a[not(@disabled)]')
for seat in seats:
    print(seat.text)

sleep(20)

browser.close()
