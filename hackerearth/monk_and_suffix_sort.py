s, k = tuple(input().split())
k = int(k)
a = []
for i in range(len(s)):
    a.append(s[i:])
a.sort()
print(a[k-1])
