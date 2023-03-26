#include <bits/stdc++.h>
#define maxN 100
#define maxW 100
using namespace std;
 
int dp[maxN][maxW][maxW][maxW];
 
int maxobject(int* arr, int n, int w1, int w2,int w3, int i)
{
    if (i == n)
        return 0;
    if (dp[i][w1][w2][w3] != -1)
        return dp[i][w1][w2][w3];
 
    int ob1 = 0, ob2 = 0,ob3=0, ob0 = 0;
 
    if (w1 >= arr[i])
        ob1 = 1 +
         maxobject(arr, n, w1 - arr[i], w2,w3, i + 1);
 
    if (w2 >= arr[i])
        ob2 = 1 +
         maxobject(arr, n, w1, w2 - arr[i],w3, i + 1);
    
    if (w3 >= arr[i])
        ob3 = 1 +
         maxobject(arr, n, w1, w2 ,w3-arr[i], i + 1);
 
    ob0 = maxobject(arr, n, w1, w2,w3, i + 1);
 
    dp[i][w1][w2][w3] = max(ob0, max(ob1, max(ob2,ob3)));
 
    return dp[i][w1][w2][w3];
}
 
int main()
{
    int n;
    cout<<"Enter no of objects :";
    cin>>n;
    int arr[n];
    cout<<"Enter weights of objects :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    memset(dp, -1, sizeof(dp));
    int w1, w2,w3;
    cout<<"Enter capacities of trucks :";
    cin>>w1>>w2>>w3;
    cout << maxobject(arr, n, w1, w2,w3, 0);
    return 0;
}