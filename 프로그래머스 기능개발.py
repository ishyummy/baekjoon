from collections import deque


def solution(progresses, speeds):       # 작업은 FIFO 이므로 deque 사용
    answer = []
    queue = deque(progresses)
    speed = deque(speeds)

    while queue:
        count = 0
        for i in range(len(queue)):
            queue[i] += speed[i]

        if queue[0] >= 100:
            while True:
                count += 1
                queue.popleft()
                speed.popleft()
                if not queue or queue[0] < 100:
                    break
            answer.append(count)
    return answer


progresses = [95, 90, 99, 99, 80, 99]
speeds = [1, 1, 1, 1, 1, 1]
print(solution(progresses, speeds))