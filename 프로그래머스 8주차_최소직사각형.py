def solution(sizes):
    answer = 0
    w = []
    h = []
    for size in sizes:
        size.sort()
    for size in sizes:
        w.append(size[0])
        h.append(size[1])
    return max(w) * max(h)


sizes = [[60, 50], [30, 70], [60, 30], [80, 40]]
print(solution(sizes))
