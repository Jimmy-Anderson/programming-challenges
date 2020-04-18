t=int(input())
for i in range(t):
	x1=int(input())
	y1=int(input())
	x2=int(input())
	y2=int(input())
	if x1==x2 and y2-y1==1:
		print("up\n")
	elif x1==x2 and y1-y2==1:
		print("down\n")
	elif y1==y2 and x1-x2==1:
		print("left\n")
	elif y1==y2 and x2-x1==1:
		print("right\n")
	else:
		print("sad\n")
		
