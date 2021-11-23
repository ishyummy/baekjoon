def rotate(arr, query):
    change = []
    temp = arr[query[0]-1][query[1]-1]
    
    for i in range(query[1], query[3]):
        change.append(temp)
        arr[query[0]-1][i], temp = temp, arr[query[0]-1][i]
        
    for i in range(query[0], query[2]):
        change.append(temp)
        arr[i][query[3]-1], temp = temp, arr[i][query[3]-1]
        
    for i in range(query[3]-2, query[1]-2, -1):
        change.append(temp)
        arr[query[2]-1][i], temp = temp, arr[query[2]-1][i]
        
    for i in range(query[2]-2, query[0]-2, -1):
        change.append(temp)
        arr[i][query[1]-1], temp = temp, arr[i][query[1]-1]
    return arr, min(change)


def solution(rows, columns, queries):
    answer = []
    arr = [[i*columns+j+1 for j in range(columns)] for i in range(rows)]
    for query in queries:
        arr, n = rotate(arr, query)
        answer.append(n)
    return answer


rows = 6
columns = 6
queries = [[2,2,5,4],[3,3,6,6],[5,1,6,3]]
print(solution(rows, columns, queries))
