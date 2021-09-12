n=int(input())
a=[]
for i in range(n):
    c=0
    a.append(input())
    if(i==0):
        print(0)
        continue
    for j in range(i):
        if a[j]<a[i]:
            c+=1
    print(c)