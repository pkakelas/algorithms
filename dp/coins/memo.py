A = [1, 2, 3, 4]
mem = {}

def k(c):
    if c in mem:
        return mem[c]
    if c == 0:
        return 0
    r = c + 1
    for i in range(len(A)):
        if c - A[i] >= 0:
            r = min(r, k(c - A[i])) + 1

    mem[c] = r
    return r

print k(200)
