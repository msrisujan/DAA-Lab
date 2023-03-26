INF=float("inf")
t=int(input("Enter no of matrices :"))
print("Enter order of each matrix")
p=[]
for i in range(t):
    n,m=map(int,input().split())
    p.append(n)
p.append(m)
dp=[[INF for i in range(t+1)]for j in range(t+1)]
for i in range(1,t+1) : dp[i][i]=0
for i in range(1,t+1):
    for j in range(1,t-i+1):
        for k in range(j,j+i):
            dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+p[j-1]*p[k]*p[j+i])
print(dp[1][t])