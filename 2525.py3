h, m = map(int, input().split())
t = int(input())
print((h + (m + t) // 60) % 24, (m + t) % 60)