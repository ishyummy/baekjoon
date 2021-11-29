from itertools import combinations
from collections import Counter


def solution(orders, course):
    answer = []
    for c in course:
        a = []
        for order in orders:
            if len(order) >= c:
                for comb in list(combinations(sorted(list(order)), c)):
                    a.append((''.join(comb)))
        b = Counter(a).most_common()
        answer += [x for x, n in b if n >=2 and n == b[0][1]]
    return sorted(answer)


orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
course = [2, 3, 4]
print(solution(orders, course))
