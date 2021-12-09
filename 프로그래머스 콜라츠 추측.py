def solution(num):
    i = 0
    while True and i <= 500:
        if num == 1:
            break
        if num%2:
            num = num * 3 + 1
        else:
            num //= 2
        i += 1
    return i if i <= 500 else -1


n = 6
print(solution(n))
