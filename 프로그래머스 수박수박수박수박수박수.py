def solution(n):
    answer = '수박' * (n//2) + '수' * (n % 2)
    return answer


n = 5
print(solution(n))