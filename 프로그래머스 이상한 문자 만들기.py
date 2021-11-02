def solution(s):
    answer = ''
    i = 0
    for c in s:
        if c == ' ':
            answer += c
            i = 0
        else:
            if i % 2:
                answer += c.lower()
            else:
                answer += c.upper()
            i += 1
    return answer


s = "try hello world"
print(solution(s))
