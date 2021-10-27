def solution(sizes):
    W, H = 0, 0
    for w, h in sizes:
        W = max(W, w, h)
        H = max(H, min(w, h))
    return W * H


sizes = [[60, 50], [30, 70], [60, 30], [80, 40]]
print(solution(sizes))
