def solution(record):
    answer = []
    log_list = []
    username_dict = {}      # user ID 와 nick name 을 dictionary type 으로 저장
    for i in record:        # record 를 공백 기준 split 하여 저장
        log_list.append(list(i.split()))
    for log in log_list:    # dictionary 에 이름 채우는 과정
        if log[0] == "Enter":
            if log[1] in username_dict:
                if username_dict[log[1]] != log[2]:     # 이미 Enter 기록이 있지만 다른 nick name 사용 시 업데이트
                    username_dict[log[1]] = log[2]
            else:
                username_dict[log[1]] = log[2]          # 첫 Enter 시 그대로 기록
        elif log[0] == "Change":                        # Change 로 nick name 업데이트
            username_dict[log[1]] = log[2]
    for log in log_list:            # log list 다시 읽으며 dictionary 값에 따라 nick name 출력
        if log[0] == "Enter":
            answer.append(username_dict[log[1]]+"님이 들어왔습니다.")
        elif log[0] == "Leave":
            answer.append(username_dict[log[1]]+"님이 나갔습니다.")

    return answer


record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
print(solution(record))