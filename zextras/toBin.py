import math
n = int(input())
n1 = 0
while(n >= 1):
    k = int(math.log(n, 2))
    n1 += 10**k
    n = n % (2**k)
print(n1)
