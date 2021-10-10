answer = 0
prime = [0 for i in range(3000)]        # 합성수를 1로 체크


def dfs(nums, visit, i, plus):          # 조합을 DFS로 구현
    global prime
    global answer
    if sum(visit) == 3:
        if not prime[plus]:
            answer += 1
        return
    if i >= len(nums):
        return
    visit[i] = 1
    dfs(nums, visit, i + 1, plus + nums[i])
    visit[i] = 0
    dfs(nums, visit, i + 1, plus)


def solution(nums):
    global prime
    visit = [0 for i in range(len(nums))]   # 조합에 포함 여부를 체크
    for i in range(2, 3000):
        if prime[i]:
            continue
        j = 2 * i
        while j < 3000:
            prime[j] = 1
            j += i
    dfs(nums, visit, 0, 0)
    return answer


nums = [1,2,7,6,4]
print(solution(nums))