import math
for i in range(int(input())):
    k, m, n = map(int, input().split())
    ll = math.ceil(math.log(m/k, n))
    print(ll)
    k = k*n**ll
    p = ll
    if(k != m):
        d = (k-m)//2
        print(d)
        k = k-2*d
        p += d
        if(k != m):
            p += 1
    print(p)
