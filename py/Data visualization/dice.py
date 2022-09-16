from plotly.graph_objs import Bar, Layout
from plotly import offline
from die import Die

# 投掷两个骰子
d6 = Die()
d10 = Die(10)

results = []
roll_sum = 10000
# 生成数据
for roll_num in range(roll_sum):
    result = d6.roll() + d10.roll()
    results.append(result)

# 分析结果
frequencies = []
for val in range(2, d6.side_num + d10.side_num + 1):
    frequency = results.count(val)
    frequencies.append(frequency)


x_values= list(range(2, d6.side_num + d10.side_num + 1)) # 横坐标的值
data = [Bar(x = x_values, y = frequencies)] # 数据点

# 设置参数
x_axis_config = {'title': '结果', 'dtick': 1} # 'dtick': 1 显示所有刻度
y_axis_config = {'title': '结果的频率'}
my_layout = Layout(title = '投一个D6 一个D10 1000次的结果', xaxis = x_axis_config, yaxis = y_axis_config)

# 画出图表
offline.plot({'data': data, 'layout': my_layout}, filename = 'd6_d10.html')