import plotly.express as px
import pandas as pd
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

# 利用 DataFrame 和 bar 画出图表
data = pd.DataFrame(data = zip(x_values, frequencies), columns = ['点数', '频率'])
fig = px.bar(data, x = '点数', y = '频率', title = '投掷一个D6 1000次的结果')

fig.show()
fig.to_dict()
fig.to_html()
fig.to_image()
fig.to_json()