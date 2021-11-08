from collections import deque


def solution(s):
    q = deque()
    for c in s:
        if q and q[-1] == c:
            q.pop()
        else:
            q.append(c)
    if q:
        return 0
    else:
        return 1


s = "baabaa"
print(solution(s))
