from collections import deque

visit = [0 for _ in range(200)]     # DFS
visit2 = [0 for _ in range(200)]    # BFS


def dfs(i, n, computers):   # DFS. 현재 위치 기준으로 연결 된 점 바로 재귀 호출
    visit[i] = 1
    for j in range(n):
        if not visit[j] and computers[i][j]:
            dfs(j, n, computers)
    return


def bfs(i, n, computers):   # BFS. 큐를 사용하여 현재 위치에서 이동 가능한 점들을 큐에 추가.
    q = deque()
    q.append(i)
    while q:
        now = q.popleft()
        visit2[now] = 1
        for j in range(n):
            if not visit2[j] and computers[now][j]:
                q.append(j)


def solution(n, computers):     # DFS
    answer = 0
    for i in range(n):
        if visit[i]:
            continue
        else:
            dfs(i, n, computers)
            answer += 1

    return answer


def solution2(n, computers):    # BFS
    answer = 0
    for i in range(n):
        if visit2[i]:
            continue
        else:
            bfs(i, n, computers)
            answer += 1

    return answer


computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
n = 3
print(solution(n, computers))
print(solution2(n, computers))
