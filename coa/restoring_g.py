def shift_left(s):
	s=s[1:]
	s=s+"0"
	return (s)
def complement(s):
	d={'0':'1','1':'0'}
	e=''.join(d[x] for x in s)
	l=len(e)
	sum=bin(int(e,2)+int("1",2))
	sum=sum[2:]
	return(sum.zfill(l))
def addzerotostring(x):
	x=list(x)
	x[-1]="0"
	return("".join(x))
def addonetostring(x):
	x=list(x)
	x[-1]="1"
	return("".join(x))

		

q=int(input("Enter the dividend :"))
m=int(input("Enter the divisor  :"))
Q=bin(q)
M=bin(m)

Q=Q[2:]  #final Q
M=M[2:]  #final M

if(len(M)>len(Q)):
	Q=Q.zfill(len(M))
else:
	M=M.zfill(len(Q))
print("Binary Value Of M :",M)
print("Binary Value Of Q :",Q)
l=len(Q)
count=l

Mc=complement(M) 

a="0"
for i in range(0,l-1):
	a=a+"0"     

while(count>0):
	s=a+Q
	
	value=shift_left(s)
	
	a=value[0:l]
	
	Q=value[l:]
	a=bin(int(a,2)+int(Mc,2))
	if(len(a[2:])==l+1):
		a=a[3:]
	else:
		a=a[2:]
	
	if(a[0]=="1"):
		a=bin(int(a,2)+int(M,2))
		if(len(a[2:])==l+1):
			a=a[3:]
		else:
			a=a[2:]
		
		Q=addzerotostring(Q)
	else:
		
		
		Q=addonetostring(Q)

	
	
	count=count-1


print("Remainder in Binary Form  :",a)
print("Remainder in Decimal Form :",int(a,2))
print("Quotient in Binary Form   :",Q)
print("Quotient in Decimal Form  :",int(Q,2))