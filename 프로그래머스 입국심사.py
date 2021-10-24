def solution(n, times):
    left = 1
    right = max(times) * n
    while left < right:
        total = 0
        mid = (left+right) // 2
        print(left, right, mid)
        for t in times:
            total += mid // t
        if total > n:
            right = mid
        else:
            left = mid+1
    return left
