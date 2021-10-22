def operation(set1, set2):      # set1 과 set2의 연산 결과 set를 return
    temp = set()
    for i in set1:
        for j in set2:
            if j:
                temp.add(i + j)
                temp.add(i * j)
                temp.add(i // j)
                temp.add(i - j)
    return temp


def solution(N, number):        # 숫자를 i번 사용하여 생성 가능한 수는 숫자를 j번, i-j번 사용하여 가능한 수들의 집합끼리 연산하여 생성 가능한 수다.
    dp = [set() for i in range(9)]
    for i in range(1, 9):
        for j in range(1, i):
            dp[i] |= operation(dp[j], dp[i - j])
        dp[i].add(int(str(N)*i))
        if number in dp[i]:
            return i
    return -1


print(solution(2, 11))
