import math


def solution(n, m):
    return [math.gcd(n,m), n*m//math.gcd(n,m)]


n = 3
m = 12
print(solution(n, m))
