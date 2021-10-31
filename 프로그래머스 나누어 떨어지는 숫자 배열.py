def solution(arr, divisor):
    return sorted(a for a in arr if not a % divisor) or [-1]


arr = [5, 9, 7, 10]
divisor = 5
print(solution(arr, divisor))
