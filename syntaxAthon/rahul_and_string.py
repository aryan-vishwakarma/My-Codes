def calc(str1,str2):
    if len(str1) == 0 and len(str2) == 0:
        return True
    elif len(str1) != 0 and len(str2) != 0:
        a=str1[0]
        b=str2[0]
        s1=str1[1:]
        s2=str2[1:]
        if a.isupper() and b.isupper():
            if a==b:
                return calc(s1, s2)
            else:
                return False
        else:
            ans1=calc((a.upper()+s1),str2)
            ans2=calc(s1,str2)
            return ans1 or ans2
    elif str1.islower():
        return True
    else:
        return False
        

q=int(input())
for i in range(q):
    a=input()
    b=input()
    if(calc(a,b)):
        print(1)
    else:
        print(0)
