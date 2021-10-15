def solution(priorities, location):
    answer = 0
    for i in range(len(priorities)):
        priorities[i] = [priorities[i], i]
    while len(priorities):
        pop = priorities.pop(0)
        if priorities and max(priorities)[0] > pop[0]:
            priorities.append(pop)
        elif pop[1] == location:
            return answer+1
        else:
            answer += 1
    return answer