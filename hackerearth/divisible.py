n=int(input())
a=input().split()
s=0
for i in range(int(n/2)):
    s=s*10+int(a[i][0])
for i in range(int(n/2),n):
    s=s*10+int(a[i][-1])
if s%11==0:
    print("OUI")
else:
    print("NON")