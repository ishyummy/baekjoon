def solution(n):
    answer = 0
    for i in range(2, n):
        if (n-1)%i == 0:
            return i


n = 13
print(solution(n))
