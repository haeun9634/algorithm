n = int(input())
n = 1000 - n

coins = [500, 100, 50, 10, 5, 1]

result = 0

for coin in coins:
    result += n // coin
    n %= coin

print(result)
