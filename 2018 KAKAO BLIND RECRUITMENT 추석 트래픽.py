def solution(lines):
    answer = -1
    time_log = []
    for log in lines:
        temp = log.split()
        end = temp[1]
        time = float(temp[2][:-1])
        temp2 = end.split(':')
        end_time = float(temp2[0])*3600 + float(temp2[1])*60 + float(temp2[2])
        start_time = end_time - time + 0.001
        time_log.append([round(start_time, 3), end_time])
    for i in range(len(time_log)):
        count = 1
        for j in range(i+1, len(time_log)):
            if time_log[j][1] >= time_log[i][1] + 3.999:
                break
            if time_log[j][0] < time_log[i][1] + 1:
                count += 1
        if count > answer:
            answer = count
    return answer


lines = ["2016-09-15 20:59:57.421 0.351s",
         "2016-09-15 20:59:58.233 1.181s",
         "2016-09-15 20:59:58.299 0.8s",
         "2016-09-15 20:59:58.688 1.041s",
         "2016-09-15 20:59:59.591 1.412s",
         "2016-09-15 21:00:00.464 1.466s",
         "2016-09-15 21:00:00.741 1.581s",
         "2016-09-15 21:00:00.748 2.31s",
         "2016-09-15 21:00:00.966 0.381s",
         "2016-09-15 21:00:02.066 2.62s"]
print(solution(lines))
