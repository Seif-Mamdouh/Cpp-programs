import datetime as dt
import matplotlib.pyplot as plt
from matplotlib import style
import pandas as pd
import pandas_datareader.data as web

class StockFactory:
    def __init__(self, stock):
        self.stock = stock
    def get_stock_data(self, start, end):
        web.DataReader(self.stock, 'yahoo', start, end)


stock = input('Put in stock name: ')

start_time_year = int(input('What year do you want the start to be? '))
start_time_month = int(input('What month do you want the start to be? '))
start_time_day = int(input('What day do you want the start to be ? '))

end_time_year = int(input('What year do you want the end to be ? '))
end_time_month = int(input('What month do you want the end to be ? '))
end_time_day = int(input('What day do you want the end to be ? '))

start = dt.datetime(start_time_year, start_time_month, start_time_day)
end = dt.datetime(end_time_year, end_time_month, end_time_day)
df=pd.read_csv('tsla.csv', parse_dates=True, index_col=0)


stockFactory = StockFactory(stock)
print(stockFactory.get_stock_data(start, end))

df.plot()
plt.show()
