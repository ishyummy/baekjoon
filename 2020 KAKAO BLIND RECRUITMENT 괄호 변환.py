def check(w):           # 올바른 괄호 문자열인지 검사하는 함수
    count = 0
    for c in w:
        if c == '(':
            count += 1
        else:
            count -= 1
        if count < 0:
            return 0
    return 1


def step4(u, v):        # 4단계 진행
    temp = '('
    temp += step123(v)
    temp += ')'

    for c in u[1:len(u) - 1]:
        if c == '(':
            temp += ')'
        else:
            temp += '('
    return temp


def step123(w):     # 1~3단계 재귀로 진행
    u = ''
    count = 0
    if not w:
        return w
    for c in w:
        if c == '(':
            count += 1
        else:
            count -= 1
        u += c
        if count == 0:
            break
    v = w[len(u):]

    if check(u):
        return u + step123(v)
    else:
        return step4(u, v)


def solution(p):
    return step123(p)


p = "()))((()"
print(solution(p))