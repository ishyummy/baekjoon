def solution(arr, divisor):
    answer = []
    for a in arr:
        if not a % divisor:
            answer.append(a)
    if not answer:
        answer.append(-1)
    return sorted(answer)


arr = [5, 9, 7, 10]
divisor = 5
print(solution(arr, divisor))
