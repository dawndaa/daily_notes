# 线程池 一次性开辟一些线程 直接给线程池提交任务即可 无需管理线程调度
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor
import time

def fn(name):
	print(name)

if __name__ == '__main__':
	# 创建线程池
	with ThreadPoolExecutor(50) as t:
		for i in range(1000):
			t.submit(fn, name = f"线程{i}")
	# 线程池中的任务结束后 才会继续执行后续任务
	print("over!")
