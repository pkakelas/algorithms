A = [1, 7, 11]
DP = [0]
c = 14

for i in range(1, c + 1):
    r = c
    for j in A:
        if i >= j:
            r = min(r, DP[i - j] + 1)
    DP.append(r)

print DP[c]
