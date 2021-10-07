def solution(numbers, hand):
    answer = ''
    L_row = 3       # 좌 우 엄지의 좌표를 각각 기록
    L_col = 0
    R_row = 3
    R_col = 2
    keypad = {      # 키 패드의 좌표를 미리 저장
        1: [0, 0],
        2: [0, 1],
        3: [0, 2],
        4: [1, 0],
        5: [1, 1],
        6: [1, 2],
        7: [2, 0],
        8: [2, 1],
        9: [2, 2],
        0: [3, 1]
    }

    for num in numbers:         # 1, 4, 7 은 왼쪽, 3, 6, 9는 오른쪽이 이동
        if num == 1 or num == 4 or num == 7:
            L_row = keypad[num][0]
            L_col = keypad[num][1]
            answer += 'L'
        elif num == 3 or num == 6 or num == 9:
            R_row = keypad[num][0]
            R_col = keypad[num][1]
            answer += 'R'
        else:                   # 2, 5, 8, 0 은 좌우 좌표의 거리와 주 사용 손을 고려하여 결정
            L_dist = abs(keypad[num][0] - L_row) + abs(keypad[num][1] - L_col)
            R_dist = abs(keypad[num][0] - R_row) + abs(keypad[num][1] - R_col)
            if L_dist < R_dist:
                L_row = keypad[num][0]
                L_col = keypad[num][1]
                answer += 'L'
            elif R_dist < L_dist:
                R_row = keypad[num][0]
                R_col = keypad[num][1]
                answer += 'R'
            else:
                if hand == 'left':
                    L_row = keypad[num][0]
                    L_col = keypad[num][1]
                    answer += 'L'
                else:
                    R_row = keypad[num][0]
                    R_col = keypad[num][1]
                    answer += 'R'

    return answer


numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
hand = "right"
print(solution(numbers, hand))