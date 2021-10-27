def solution(price, money, count):
    return max((count * (count+1) * price) // 2 - money, 0)


price = 3
money = 20
count = 4
print(solution(price, money, count))
