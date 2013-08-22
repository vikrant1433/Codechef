t = int(raw_input())
 
while(t):
    a = raw_input()
    a = a.split()
    L = map(int, a)
    L.sort()
    L[1] -= 1
    L[2] -= 2
    print (L[0]*L[1]*L[2])%(10**9 + 7)
    t -= 1