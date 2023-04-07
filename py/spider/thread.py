# 线程与进程  进程是资源单位 线程是执行单位
from threading import Thread # 导入线程类

def func(name):
	for i in range(1000):
		print(f"{name}{i} ")

if __name__ == "__main__":
	t = Thread(target = func, args = ('bb', )) # 创建一个新线程
	# 用args给线程传递参数 其中args = () 后面是元组
	t.start() # 线程就绪 具体何时执行由cpu调度

	for i in range(1000):
		print(f"main{i}")