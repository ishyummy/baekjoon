h, m, s = map(int, input().split())
t = int(input())
s2 = (s + t) % 60
m2 = (m + (s + t) // 60) % 60
h2 = (h + (m + (s + t) // 60) // 60) % 24
print(h2, m2, s2)