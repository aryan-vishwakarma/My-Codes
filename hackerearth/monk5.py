import math
def powerMod(a,n,b):
    if(a==1):
        return 1
    k=int(math.log(b)/math.log(a))+1
    if n>=k:
        return((powerMod(a**k%b,n//k,b)*a**(n%k))%b)
    else:
        return(a**n)
T=int(input())
for t in range(T):
    N=input()
    n=int(N)
    s=0
    i=0
    while(n-i>=0):
        if (i)%4==0:
            s+=powerMod(10,n-i,1000000009)*powerMod(n-1,i/2,1000000009)
        else:
            s-=powerMod(10,n-i,1000000009)*powerMod(n-1,i/2,1000000009)
        i+=2
    print(int(s))