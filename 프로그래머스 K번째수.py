def solution(array, commands):
    answer = []
    for command in commands:
        sub = array[command[0]-1:command[1]]
        sub.sort()
        answer.append(sub[command[2]-1])
    return answer
