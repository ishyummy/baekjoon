from collections import Counter     # 요소 별 개수 자동으로 세서 dictionary 로 저장하는 collections.Counter 사용


def solution(participant, completion):
    answer = ''

    result = Counter(participant) - Counter(completion)
    answer += list(result)[0]

    return answer


participant = ["mislav", "stanko", "mislav", "ana"]
completion = ["stanko", "ana", "mislav"]
print(solution(participant, completion))