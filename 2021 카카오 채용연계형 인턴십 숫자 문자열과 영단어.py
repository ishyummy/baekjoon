def solution(s):
    answer = ''
    table = {       # 숫자 별 영어 표기를 dictionary 로 저장
        'zero': 0,
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9
    }
    temp = ''
    for c in s:
        temp += c
        if temp in table:
            answer += str(table[temp])
            temp = ''
        elif '0' <= temp <= '9':
            answer += str(temp)
            temp = ''
    return int(answer)


s = "one4seveneight"
print(solution(s))