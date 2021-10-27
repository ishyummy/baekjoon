def solution(n, arr1, arr2):
    answer = []
    table = str.maketrans('10', '# ')
    for i in range(n):
        value = arr1[i] | arr2[i]
        answer.append(bin(value)[2:].zfill(n).translate(table))
    return answer


n = 5
arr1 = [9, 20, 28, 18, 11]
arr2 = [30, 1, 21, 17, 28]
print(solution(n, arr1, arr2))
