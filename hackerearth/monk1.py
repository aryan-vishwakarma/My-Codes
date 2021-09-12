T=int(input("Enter: "))
N,K=(int(i) for i in input().split())
a=[int(i) for i in input().split()]
K=K%N
a1=[]
for i in range(N):
    if i-K>=0:
        a1.append(a[i-K])
    else:
        a1.append(a[i-K+N])
for i in a1:
    print(i,end=' ')