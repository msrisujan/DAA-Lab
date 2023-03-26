p=list(map(int,input("Enter profits :").split()))
w=list(map(int,input("Enter weights :").split()))
c=int(input("Enter capacity :"))
dp=[[0 for i in range(c+1)]for j in range(len(p)+1)]
for i in range(1,len(p)+1):
    for j in range(1,c+1):
        if w[i-1]<=j:
            dp[i][j]=max(dp[i-1][j],p[i-1]+dp[i-1][j-w[i-1]])
        else:
            dp[i][j]=dp[i-1][j]
print(dp[len(p)][c])