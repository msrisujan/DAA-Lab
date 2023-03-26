import string
res=[]
n=int(input("enter no of matrices "))
for i in range(65,65+n):
    res.append(chr(i))
dp = [[None for i in range(n)] for j in range(n)]


def add_parr(a):
    a=str(a)
    return '('+a+')'


def matrices(first,last):
    if(first==last):
        dp[first][last]=((res[first]),)
        return dp[first][last]
    if dp[first][last] != None:
        return dp[first][last]
    else:
        res1=[]
        for k in range(first,last):
            p1=matrices(first,k)
            p2=matrices(k+1,last)

            for i in p1:
                for j in p2:
                    x=add_parr(i)+add_parr(j)
                    res1.append(x)
    dp[first][last]= tuple(res1)
    return dp[first][last]


ans=matrices(0,n-1)
for p,a in enumerate(ans):
    print(p+1,a)
