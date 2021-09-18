T = int(input())
for t in range(T):
    N = int(input())
    A = [long(i) for i in input().split()]
    m = A[0] ^ A[1]
    for i in range(N-1):
        for j in range(i+1, N):
            p = A[i] ^ A[j]
            if m > p:
                m = p
    print(m)
