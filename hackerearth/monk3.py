def checkBiggest(a,n):
    b=a
    a=list(a)
    for i in range(n):
        a=shift(a,n)
        c1=str(''.join(a))
        if c1>b:
            b=c1
    return b
def shift(a,n):
    a1=[a[i+1] if i+1<n else a[i+1-n] for i in range(n)]
    return a1
T=int(input())
for u in range(T):
    N,K=(int(i) for i in input().split())
    A=input()
    a=list(A)
    B=checkBiggest(A,N)
    c=0
    f=0
    while(True):
        if str(''.join(a))==B:
            c+=1
        if c==K:
            break
        f+=1
        a=shift(a,N)
    print(f)