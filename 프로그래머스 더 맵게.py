import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0] < K and len(scoville) > 1:
        one = heapq.heappop(scoville)
        two = heapq.heappop(scoville)
        heapq.heappush(scoville, one + two*2)
        answer += 1

    if scoville[0] >= K:
        return answer
    else:
        return -1


scoville = [1, 2, 3, 9, 10, 12]
K = 7
print(solution(scoville, K))