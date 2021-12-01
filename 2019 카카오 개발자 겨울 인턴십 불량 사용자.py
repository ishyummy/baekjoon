count = 0
his = []


def check(user, ban):
    for c in range(len(user)):
        if ban[c] == '*':
            continue
        elif user[c] != ban[c]:
            return False
    return True


def dfs(user_id, banned_id, basket):
    global count
    if not banned_id:
        basket.sort()
        if basket not in his:
            his.append(basket)
            count += 1
        return
    ban = banned_id[0]
    for i in range(len(user_id)):
        if len(user_id[i]) == len(ban):
            if check(user_id[i], ban):
                dfs(user_id[0:i]+user_id[i+1:], banned_id[1:], basket+[user_id[i]])
    

def solution(user_id, banned_id):
    dfs(user_id, banned_id, [])
    return count


user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
banned_id = ["fr*d*", "abc1**"]
print(solution(user_id, banned_id))
