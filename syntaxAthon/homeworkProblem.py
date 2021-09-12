import math
t=int(input())
a=[int(i) for i in input().split()]
for n in a:
    # print(int(math.pow(n,0.5)) + int(math.pow(n,(1/3))) - int(math.pow(n,(1/6))))
    print(int(math.pow(n+1,0.5)), int(math.pow(n+1,(1/3))), int(math.pow(n+1,(1/6))))