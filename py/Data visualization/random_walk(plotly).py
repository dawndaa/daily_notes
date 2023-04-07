import pandas as pd
import plotly.express as px
from random_walk import RandomWalk

# 随机漫步

while True:
    rw = RandomWalk(50000)
    rw.fill_walk()

    x_values = rw.x_values
    y_values = rw.y_values
    points_nums = range(rw.num_points)

    data = pd.DataFrame(data = zip(y_values), index = x_values, columns = ['随机漫步'])
    fig = px.scatter(data, color = points_nums)
    
    fig.show()

    flag = input("Do you want to quit?y/n ")
    if flag == 'y':
        break