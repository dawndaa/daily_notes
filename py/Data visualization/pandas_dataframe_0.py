import pandas as pd

x_vals = [1, 2, 3, 4]
y_vals = [1, 4, 9, 16]
data = pd.DataFrame(data = zip(x_vals, y_vals), columns = ['值', '值的平方'])

print(data)