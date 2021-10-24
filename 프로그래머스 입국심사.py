def solution(n, times):     # T초 경과 시 각자 처리할 수 있는 사람 수의 합을 구하고, 그것이 n이 되도록 T를 조절해감.
    left = 1                # T 탐색은 binary search 사용.
    right = max(times) * n
    while left < right:
        total = 0
        mid = (left+right) // 2
        for t in times:
            total += mid // t
        if total >= n:      # n인 경우에도 최솟값을 구해야하므로 탐색 계속 진행
            right = mid     # mid가 이미 최솟값일 수도 있으므로 mid를 포함함
        else:
            left = mid + 1  # n보다 작을 경우는 고려하지 않으므로 mid + 1
    return left             # 마지막 loop은 left == right로 범위 끝까지 좁힘, mid값 계산하기 전에 종료되므로 left or right를 return.
