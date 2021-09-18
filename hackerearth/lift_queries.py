
t = int(input())
a = 0
b = 7
for q in range(t):
    n = int(input())
    if(abs(a-n) <= abs(b-n)):
        print('A')
        a = n
    else:
        print('B')
        b = n
