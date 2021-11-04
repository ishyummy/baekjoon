def solution(a, b):
    return (a+b)*(max(a,b)-min(a,b)+1)//2


a = 3
b = 5
print(solution(a, b))
