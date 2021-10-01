n = int(input())

for _ in range(n):
    line = input().split()
    num = 0
    for i in line:
        if i == '@':
            num *= 3
        elif i == '%':
            num += 5
        elif i == '#':
            num -= 7
        else:
            num = float(i)

    print("%.2f" % num)