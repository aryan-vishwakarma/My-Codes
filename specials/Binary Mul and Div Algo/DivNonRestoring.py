import math


def addOneBit(a, b, x=0):
    s = a ^ (b ^ x)
    c = x & (a ^ b) | a & b
    return s, c


def add(a, b, m, carry=0):
    if m != 0:
        a1 = a[0:m-1]
        b1 = b[0:m-1]
        s, c = addOneBit(int(a[m-1]), int(b[m-1]), carry)
        r = ''
        if m != 1:
            r = str(add(a1, b1, m-1, c)) + str(s)
        else:
            r = str(s)
        return r


def toBin(n):  # integer as input
    n1 = 0
    while(n >= 1):
        k = int(math.log(n, 2))
        n1 += 10**k
        n = n % (2**k)
    return n1


def compliment(n):  # accepts string as input
    n1 = ''
    for i in n:
        if i == '1':
            n1 = n1 + '0'
        else:
            n1 = n1 + '1'
    return n1


def twosCompliment(n, m):
    n1 = compliment(n)
    return add(n1, '0'*(m-1) + '1', m)


def toBinTwos(n, m):
    if n > 0:
        return '0'*(m-int(math.log(n, 2)) - 1) + str(toBin(n))
    return twosCompliment('0'*(m-int(math.log(abs(n), 2)) - 1) + str(toBin(abs(n))), m)


def shiftR(a, q, bits):
    a1 = a[0] + a[0:bits - 1]
    q1 = a[bits - 1] + q[0:bits - 1]
    qn1 = q[bits - 1]
    return a1, q1, qn1


def shiftL(a, q):
    a = a[1:] + q[0]
    q = q[1:] + '0'
    return a, q


Q = int(input("Enter dividend : "))
M = int(input("Enter divisor : "))
bits = int(input("Enter no. bits : "))
count = bits
M = toBinTwos(M, bits)
Q = toBinTwos(Q, bits)

A = '0'*bits
print('Q = ', Q)
print('M = ', M)
print("Step\t\tA\t\tQ\t\tAction\t\tCount")
print('0\t\t', A, '\t\t', Q, '\t\t', "Initial\t\t", count, '\n')
steps = 1
A, Q = shiftL(A, Q)
count = count - 1
print(steps, '\t\t', A, '\t\t', Q, '\t\t', "Shift\t\t", count, '\n')
A = add(A, twosCompliment(M, bits), bits)
print(steps, '\t\t', A, '\t\t', Q, '\t\t', "A<-A-M\t\t", count, '\n')


while True:
    steps = steps + 1
    if A[0] == '1':
        if count == 0:
            A = add(A, M, bits)
            print(steps, '\t\t', A, '\t\t', Q,
                  '\t\t', "A<-A+M\t\t", count, '\n')
            break
        A, Q = shiftL(A, Q)
        count = count - 1
        print(steps, '\t\t', A, '\t\t', Q, '\t\t', "Shift\t\t", count, '\n')
        A = add(A, M, bits)
        print(steps, '\t\t', A, '\t\t', Q, '\t\t', "A<-A+M\t\t", count, '\n')
    else:
        Q = Q[:bits - 1] + '1'
        print(steps, '\t\t', A, '\t\t', Q, '\t\t', "Q(0)=1\t\t", count, '\n')
        if count == 0:
            break
        A, Q = shiftL(A, Q)
        count = count - 1
        print(steps, '\t\t', A, '\t\t', Q, '\t\t', "Shift\t\t", count, '\n')
        A = add(A, twosCompliment(M, bits), bits)
        print(steps, '\t\t', A, '\t\t', Q, '\t\t', "A<-A-M\t\t", count, '\n')
