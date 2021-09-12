def rev(s):
    return s[::-1]

n=int(input())
s=[]
for i in range(n):
    s.append(input())

s1=sorted(s, key=len)
s2=[i.strip() for i in s1]
for i in range(len(s2)):
    j=i
    while(len(s2[i])==len(s2[j]) and j<len(s2)):
        if(s2[i]==rev(s2[j])):
            print(len(s2[i]), s2[i][(len(s2[i])-1)//2])
            break
        j+=1