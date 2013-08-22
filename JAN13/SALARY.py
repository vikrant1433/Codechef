t = int(raw_input())
while(t):
	n = int(raw_input())
	L = raw_input().split()
	L = map(int, L)
	count = 0
	minimum = min(L)
	for i in L:
		count = count + (i - minimum)
	print count
	t -= 1