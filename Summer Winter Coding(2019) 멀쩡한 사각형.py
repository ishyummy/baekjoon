import math


def solution(w, h):
    return w*h - (w+h-math.gcd(w, h))


w = 100_000_000
h = 100_000_000
print(solution(w, h))