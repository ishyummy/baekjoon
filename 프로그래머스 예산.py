from collections import deque


def solution(d, budget):
    answer = 0
    d.sort()
    q = deque(d)
    while q:
        pop = q.popleft()
        if pop > budget:
            break
        else:
            answer += 1
            budget -= pop
    return answer