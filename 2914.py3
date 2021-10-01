n, m = map(int, input().split())
if n > 1:
    print(n * (m - 1) + 1)
else:
    print(n * m)