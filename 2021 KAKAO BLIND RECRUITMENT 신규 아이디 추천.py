def solution(new_id):       # 단계별 진행
    step_1 = new_id.lower()

    step_2 = ""
    for i in step_1:
        if 'a' <= i <= 'z' or '0' <= i <= '9' or i == '-' or i == '_' or i == '.':
            step_2 += i

    step_3 = ""
    flag = 0
    for i in step_2:
        if i != '.':
            step_3 += i
            flag = 0
        elif i == '.' and flag == 0:
            step_3 += i
            flag = 1

    start = 0
    end = len(step_3)
    if step_3[0] == '.':
        start += 1
    if step_3[-1] == '.':
        end -= 1
    step_4 = step_3[start:end]

    if len(step_4) == 0:
        step_5 = "a"
    else:
        step_5 = step_4

    if len(step_5) >= 16:
        step_6_1 = step_5[:15]
    else:
        step_6_1 = step_5
    if step_6_1[-1] == '.':
        step_6_2 = step_6_1[:-1]
    else:
        step_6_2 = step_6_1

    step_7 = step_6_2
    for i in range(3 - len(step_6_2)):
        step_7 += step_6_2[-1]

    answer = step_7
    return answer


new_id = "...!@BaT#*..y.abcdefghijklm"
print(solution(new_id))