#include<bits/stdc++.h>
using namespace std;
int search(int a[],int n,int k)
{
    for(int i=0;i<k;i++)
    {
        if(a[i]==n)
        {
            return 1;
        }
    }
    return -1;
}
int dynamic(int n,int a[],int k)
{
    int change[n];
    for(int i=0;i<k;i++)
    {
        change[a[i]-1]=1;
    }
    int dym[k],dem[k];
    for(int i=2;i<=n;i++)
    {
        if(search(a,i,k)==-1)
        {
            int m=0;
            while(a[m]<i)
            {
                dem[m]=a[m];
                m++;
            }
            for(int j=0;j<m;j++)
            {
                int pos=i-dem[j];
                dym[j]=change[pos-1];
            }
            int temp=1+*min_element(dym,dym+m);
            change[i-1]=temp;
        }
    }
    return change[n-1];
}
int main()
{
    int n,k;
    cout<<"enter the value :";
    cin>>n;
    cout<<"enter no of denominations :";
    cin>>k;
    int b[k];
    cout<<"enter the denominations :";
    for(int i=0;i<k;i++)
    {
        cin>>b[i];
    }
    sort(b,b+k);
    int x=dynamic(n,b,k);
    cout<<"min no of coins : "<<x;
    return 0;
}