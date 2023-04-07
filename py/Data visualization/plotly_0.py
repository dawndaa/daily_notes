from plotly.graph_objs import Bar, Layout
from plotly import offline
from die import Die

die = Die()

results = []
roll_sum = 1000
# 生成数据
for roll_num in range(roll_sum):
    result = die.roll()
    results.append(result)

# 分析结果
frequencies = []
for val in range(1, die.side_num + 1):
    frequency = results.count(val)
    frequencies.append(frequency)


x_values= list(range(1, die.side_num + 1)) # 横坐标的值
data = [Bar(x = x_values, y = frequencies)] # 数据点

# 设置参数
x_axis_config = {'title': '结果'}
y_axis_config = {'title': '结果的频率'}
my_layout = Layout(title = '投一个D6 1000次的结果', xaxis = x_axis_config, yaxis = y_axis_config)

# 画出图表
offline.plot({'data': data, 'layout': my_layout}, filename = 'd6.html')