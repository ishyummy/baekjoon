a = input()
op = input()
b = input()

if op == '+':
    if a == b:
        print("2", end="")
        for _ in range(len(a)-1):
            print("0", end="")
    else:
        if len(a) > len(b):
            new = a[:len(a)-len(b)] + b
        else:
            new = b[:len(b)-len(a)] + a
        print(new)
else:
    print("1", end="")
    for _ in range(len(a)+len(b)-2):
        print("0", end="")