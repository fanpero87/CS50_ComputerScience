import math
from cs50 import get_float

def main():
    change = positiveFloat()
    if (change >= 1):
        whole_number_part = int(change)
        count1 = whole_number_part * 4
        decimal_number_part = int((change - whole_number_part) * 100)
        count2 = calculateCoin(decimal_number_part)
        count = count1 + count2
    else:
        decimal_number_part = int(change * 100)
        count = calculateCoin(decimal_number_part)
    print(count)

def calculateCoin(coin):
    quarters = 25
    dimes = 10
    nickels = 5
    pennies = 1
    count = 0
    while (coin >= quarters):
        y = int(coin / quarters)
        coin = coin % quarters
        count = count + y
    while (coin >= dimes):
        y = int(coin / dimes)
        coin = coin % dimes
        count = count + y
    while (coin >= nickels):
        y = int(coin / nickels)
        coin = coin % nickels
        count = count + y
    while (coin >= pennies):
        y = int(coin / pennies)
        coin = coin % pennies
        count = count + y
    return count

def positiveFloat():
    while True:
        c = get_float("Change owed: \n")
        if c > 0:
            break
    return c

main()