def solution(strings, n):
    strings.sort()
    return sorted(strings, key = lambda x: x[n])


strings = ["abce", "abcd", "cdx"]
n = 2
print(solution(strings, n))
