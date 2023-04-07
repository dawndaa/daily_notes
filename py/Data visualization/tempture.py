import csv
from datetime import datetime
import matplotlib.pyplot as plt

file_name = '3070601.csv'
with open(file_name) as f:
    reader = csv.reader(f)
    head = next(reader)
    print(head)
    
    highs = []
    lows = []
    dates = []
    for row in reader:
        try:
            high = int(row[5])
            low = int(row[6])
            date = datetime.strptime(row[2], '%Y-%m-%d')
        except:
            print(f"Missing message for {row[2]}")
        else:
            highs.append(high)
            lows.append(low)
            dates.append(date)

    fig, ax = plt.subplots()
    ax.plot(dates, highs, c = 'red', alpha = 0.5)
    ax.plot(dates, lows, c = 'green', alpha = 0.5)
    ax.fill_between(dates, highs, lows, facecolor = 'blue', alpha = 0.1)

    ax.set_xlabel('日期')
    ax.set_ylabel('温度(F)')
    ax.set_title('2022年阿拉斯加气温图')
    fig.autofmt_xdate()

    plt.show()