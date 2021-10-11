def solution(n, lost, reserve):     # 왼쪽 학생부터 탐색, lost 이면 본인 기준 왼쪽 학생 다음 오른쪽 학생 순서로 reserve 인지 검사.
    answer = 0                      # Greedy
    student = [1 for i in range(n)]
    lost_f = []
    for l in lost:                  # lost 와 reserve 중복 검사
        if l in reserve:
            reserve.remove(l)
        else:
            lost_f.append(l)
    for l in lost_f:
        student[l-1] = 0
    for r in reserve:
        student[r-1] = 2
    for i in range(n):
        if student[i] == 0:
            if i > 0 and student[i-1] == 2:
                student[i-1] = 1
                student[i] = 1
            elif i < n-1 and student[i+1] == 2:
                student[i+1] = 1
                student[i] = 1
            else:
                answer += 1
    return n - answer


n = 5
lost = [2, 4]
reserve = [1, 3, 5]
print(solution(n, lost, reserve))