#include<bits/stdc++.h>
using namespace std;
int coinchange(vector<int>a,int n,int k)
{
    vector<int>vec;
    for(int i=k-1;i>=0;i--)
    {
        while(n>=a[i])
        {
            n-=a[i];
            vec.push_back(a[i]);
        }
    }
    return (vec.size());
}
int main()
{
    int n,k;
    cout<<"enter the value :";
    cin>>n;
    cout<<"enter no of denominations :";
    cin>>k;
    int b[k];
    vector<int>a;
    cout<<"enter the denominations :";
    for(int i=0;i<k;i++)
    {
        cin>>b[i];
        a.push_back(b[i]);
    }
    sort(a.begin(),a.end());
    int pos=a.size();
    int x=k;
    vector<int>c;
    for(int i=0;i<x;i++)
    {
        int y=coinchange(a,n,k);
        c.push_back(y);
        k--;
    }
    sort(c.begin(),c.end());
    cout<<"minimum no of coins : "<<c[0];
    return 0;
}
//this logic will work for all cases because we will check all possible cases and finds the minimum no of coins
//so even if we give 1 3 4 or 1 3 5 for change of 6 output will come correctly