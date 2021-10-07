def solution(board, moves):
    answer = 0
    basket = []
    n = len(board[0])       # board 폭 저장

    for move in moves:      # 각 move 를 시행하여 basket 에 인형 쌓기
        for i in range(n):
            if board[i][move - 1]:
                basket.append(board[i][move - 1])
                board[i][move - 1] = 0
                break

    while True:         # 더 이상 제거할 인형이 없을 때까지 basket 의 인형 제거
        for i in range(len(basket) - 1):
            if basket[i] == basket[i + 1]:
                answer += 2
                del basket[i:i + 2]
                break
        else:
            break

    return answer


board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]
print(solution(board, moves))