def solution(lottos, win_nums):
    answer = []
    zero = 0        # 0의 개수
    match = 0       # 일치하는 숫자의 개수
    for i in lottos:
        if i == 0:
            zero += 1
        elif i in win_nums:
            match += 1

    answer.append(7 - match - zero)
    answer.append(7 - match)

    for i in range(2):  # 0개 적중 시 7등이 아닌 6등이므로 수정
        if answer[i] == 7:
            answer[i] = 6

    return answer


lottos = [44, 1, 0, 0, 31, 25]
win_nums = [31, 10, 45, 1, 6, 19]
print(solution(lottos, win_nums))