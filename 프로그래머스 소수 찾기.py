from itertools import permutations


def solution(numbers):
    nums = []
    check = []
    count = 0
    for number in numbers:
        nums.append(number)
    for i in range(1, len(nums)+1):
        for permu in permutations(nums, i):
            n = int(''.join(permu))
            if n <= 1 or n in check:
                continue
            for j in range(2, int(n**(1/2))+1):
                if n%j == 0:
                    break
            else:
                check.append(n)
                count += 1
    return count


numbers = "011"
print(solution(numbers))
