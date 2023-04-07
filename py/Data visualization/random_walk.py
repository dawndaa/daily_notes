from random import choice

class RandomWalk:
    """随机漫步"""

    def __init__(self, num_points = 521):
        self.num_points = num_points

        self.x_values = [0]
        self.y_values = [0]

    # 随机生成路径
    def get_step(self):
        dir = [-1, 1]
        dis = [0, 1, 2, 3, 4]

        cur_dir = choice(dir)
        cur_dis = choice(dis)

        return cur_dir * cur_dis

    # 生成一系列点集
    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x = self.get_step()
            y = self.get_step()

            if x == 0 and y == 0:
                continue

            self.x_values.append(self.x_values[-1] + x)
            self.y_values.append(self.y_values[-1] + y)
