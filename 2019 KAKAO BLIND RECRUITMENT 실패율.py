def solution(N, stages):
    success_table = []
    reach = len(stages)
    for i in range(1, N+1):
        if reach != 0:
            fail = stages.count(i)
            success_table.append([1-fail/reach, i])
            reach -= fail
        else:
            success_table.append([1, i])
    success_table.sort()
    answer = [i[1] for i in success_table]
    return answer


N = 5
stages = [2, 1, 2, 6, 2, 4, 3, 3]
print(solution(N, stages))