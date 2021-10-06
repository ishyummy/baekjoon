def solution(s):
    answer = 1001       # 최대 입력 값이 1000이므로 MAX 값을 1001로 설정
    if len(s) == 1:     # 문자열 길이가 1인 경우는 예외로 처리
        answer = 1
    for i in range(1, len(s) // 2 + 1):     # 문자열 길이의 절반까지만 반복 가능하므로
        length = 0
        num = 1     # 압축한 문자열의 길이
        x = 0       # 자르기 시작할 문자열의 index
        while True:
            if x + 2 * i > len(s):      # 비교할 다음 sub 문자열이 없을 경우 종료
                if num > 1:
                    length += len(str(num)) + i + len(s) % i
                else:
                    length += i + len(s) % i
                break
            else:                       # 길이 i의 sub 문자열을 잘라 앞 뒤를 비교
                if s[x:x + i] == s[x + i:x + 2 * i]:
                    num += 1
                elif num > 1:
                    length += len(str(num)) + i
                    num = 1
                else:
                    length += i
            x += i

        if length < answer:
            answer = length

    return answer


s = "abcabcabcabcdededededede"
print(solution(s))
