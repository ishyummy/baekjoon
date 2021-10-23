from collections import deque


def solution(n, edge):      # BFS
    MAX = -1
    count = 0
    graph = [[] for i in range(n+1)]
    visit = [0 for i in range(n+1)]
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    q = deque()
    q.append([1, 0])
    visit[1] = 1
    while q:
        node = q.popleft()
        if node[1] == MAX:      # MAX에 현재까지 최장거리 저장
            count += 1
        else:
            MAX = node[1]
            count = 1
        for v in graph[node[0]]:
            if not visit[v]:
                visit[v] = 1
                q.append([v, node[1]+1])    # [방문한 vertex, 최단거리] 기록
    return count


n = 6
edge = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
print(solution(n, edge))
