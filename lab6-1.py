n=int(input())
a=list(i+1 for i in range(n))
i=0
while len(a)!=1:
    x=a[-1]
    if i==0:
        a=a[0::2]
    elif i==1:
        a=a[1::2]
    if(x==a[-1]):
        i=1
    else:
        i=0
print(a[0])
