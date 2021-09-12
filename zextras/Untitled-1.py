def f(a,b,c,d,t):
    return a*t**3+b*t**2+c*t+d
T=int(input())
for q in range(T):
    a,b,c,d,K=map(int,input().split())
    t=1
    while(not f(t)<=K or not f(t+1)>K):
        t+=1
    print(t)