n = int(input())
if n == 1:
    print('*')
    exit()
a = []
b = dict()
for i in range(n):
    num = int(input())
    a.append(num)
    try:
        b[num] += 1
    except KeyError:
        b[num] = 1

for i,j in b.items():
    if(j >= (n//2+1)):
        print(i)
        break;
else:
    print("*")