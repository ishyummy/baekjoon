def solution(x):
    return False if x % sum(map(int, str(x))) else True


x = 18
print(solution(x))
