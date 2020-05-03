
def convert_to_decimal(x,y,z):
	a = 1 if x=="True" else 0
	b = 1 if y=="True" else 0
	c = 1 if z=="True" else 0
	return a*4+b*2+c*1

print('Input three values corresponding to each of the following variables\n')
x=input('1. isMorning(True/False): ')
y=input('2. isMom(True/False): ')
z=input('3. isAsleep(True/False): ')

value=convert_to_decimal(x,y,z)
print(value,x,y,z)
if value==0 or value==2 or value==6:
	print('True')
else:
	print('False')
