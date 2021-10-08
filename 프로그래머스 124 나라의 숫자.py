def solution(n):
    answer = ''
    while n > 0:        # 3진법과 유사하나 각 자리수를 별개로 계산, 0을 고려하여 -1씩 보정해줘야 함
        n -= 1
        answer += '124'[n % 3]
        n //= 3
    return answer[::-1]


n = 500_000_000
print(solution(n))