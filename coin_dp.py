den=list(map(int,input("Enter denominations :").split()))
amt=int(input("Enter amount :"))
dp=[0]*(amt+1)
for i in range(min(den),amt+1):
    dp[i]=1+min([dp[i-j] for j in den if i-j>=0])
print(dp[amt])