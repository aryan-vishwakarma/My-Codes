import math
def toBin(x):
    s=''
    while x > 0:
        s = str(x%2) + s
        x = x // 2
    return s

def toDec(s):
    l = len(s)
    n = 0
    for i in range(l):
        n += int(s[i])*int(math.pow(2, l-i-1))
    return n

def isPalin(s):
    if s == s[::-1]:
        return True
    else:
        return False

for t in range(int(input())):
    n = int(input())
    nxt = 0
    while True:
        if isPalin(toBin(n+nxt)):
            print(nxt)
            break
        elif isPalin(toBin(n-nxt)):
            print(nxt)
            break
        nxt+=1
        