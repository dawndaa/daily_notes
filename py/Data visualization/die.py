from random import randint

class Die:
    def __init__(self, side_num = 6):
        self.side_num = side_num

    def roll(self):
        return randint(1, self.side_num + 1)