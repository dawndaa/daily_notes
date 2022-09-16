import matplotlib.pyplot as plt

# print(plt.style.available)
# plt.style.use('seaborn') 选择样式

x_values = range(1, 1001)
y_values = [x * x for x in x_values]

fig, ax = plt.subplots()

ax.axis([0, 1100, 0, 1100000])
# ax.plot(x_values, y_values, linewidth = 2) 折线图
ax.scatter(x_values, y_values, s = 3, c = y_values, cmap = plt.cm.Blues) 
# 散点图 c = y_values, cmap = plt.cm.Blues 通过value来设置渐变色
 
ax.set_title('平方', fontsize = 10)
ax.set_xlabel('值', fontsize = 10)
ax.set_ylabel('值的平方', fontsize = 10)

plt.savefig('../imgs/test_0.png', bbox_inches = 'tight') #保存图片
plt.show()
