answer = 0

def dfs(numbers, target, i, count):
    global answer
    if i >= len(numbers):
        if count == target:
            answer += 1
        return
    if count + sum(numbers[i:]) < target or count - sum(numbers[i:]) > target:
        return
    dfs(numbers, target, i+1, count+numbers[i])
    dfs(numbers, target, i+1, count-numbers[i])


def solution(numbers, target):
    global answer
    dfs(numbers, target, 0, 0)
    return answer


numbers = [1, 1, 1, 1, 1]
target = 3
print(solution(numbers, target))