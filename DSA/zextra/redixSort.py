a = []
d = 0


def intToString():
    global a
    a = [str(i) for i in a]


def makeSameDigits():
    global a
    global d
    a = ["0"*(d-len(a[i]))+a[i] for i in range(len(a))]


def maxDigits():
    global a
    global d
    d = len(a[0])
    for i in range(1, len(a)):
        if d > len(a[i]):
            d = len(a[i])

# def


def redixSort(n):
    global a, d


a = [1, 2, 3, 4, 50]
d = 2
intToString()
print(a)
makeSameDigits()
print(a)
