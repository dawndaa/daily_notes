# 利用py编写协程的程序
import asyncio  # 导入异步io模块
import time

async def func_0():
	print('你好！ 我叫盖亚')
	# time.sleep(4) # 当程序出现同步操作时 异步就中断了
	await asyncio.sleep(4)
	print('你好！ 我叫盖亚')

async def func_1():
	print('你好！ 我叫迪迦')
	# time.sleep(3)
	await asyncio.sleep(3)
	print('你好！ 我叫迪迦')


async def func_2():
	print('你好！ 我叫戴拿')
	# time.sleep(2)
	await asyncio.sleep(2)
	print('你好！ 我叫戴拿')

if __name__ == '__main__':
	f0 = func_0()
	f1 = func_1()
	f2 = func_2()
	tasks = [f0, f1, f2]

	t1 = time.time()
	asyncio.run(asyncio.wait(tasks))
	t2 = time.time()

	print(t2 - t1)