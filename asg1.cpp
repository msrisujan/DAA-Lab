#include<iostream>
#include<cmath>
using namespace std;
void primefactor(int n)
{
    int count=0;
    if(n%2==0)
    {
        cout<<2<<" ";
    }
    while(n%2==0)
    {
        n=n/2;
        count++;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
        while(n%i==0)
        {
            n=n/i;
            count++;
        }
        count++;
    }
    if(n>2)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<count<<endl;
}
int main()
{
    int n;
    cin>>n;
    primefactor(n);
    return 0;
}