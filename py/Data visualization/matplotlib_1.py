from matplotlib import pyplot as plt
from random_walk import RandomWalk

# 随机漫步

while True:
    rw = RandomWalk(5000)
    rw.fill_walk()

    x_values = rw.x_values
    y_values = rw.y_values
    points_nums = range(rw.num_points)

    fig, ax = plt.subplots()
    # ax.scatter(x_values, y_values, c = points_nums, cmap = plt.cm.Blues, s = 1, edgecolors = 'none')
    ax.plot(x_values, y_values, linewidth = 1)
    ax.scatter(0, 0, c = 'green', edgecolors = 'none', s = 5)
    ax.scatter(x_values[-1], y_values[-1], c = 'red', edgecolors = 'none', s = 5)

    # 隐藏坐标轴
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

    plt.show()

    flag = input("Do you want to quit?y/n ")
    if flag == 'y':
        break