#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of parts :";
    cin>>n;
    double weight;
    cout<<"Enter total weight :";
    cin>>weight;
    double x[n],p[n],w[n];
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
    cout<<"Enter profit and weight of each part"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        cin>>w[i];
    }
    double wei=0;
    for(int i=0;i<n;i++)
    {
        if(wei+w[i]<=weight)
        {
            x[i]=1;
            wei=wei+w[i];
        }
        else
        {
            x[i]=(weight-wei)/w[i];
            wei=weight;
            break;
        }
    }
    cout<<"Max value of profit can be obtained by :";
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    int m=0;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        m=m+(x[i]*p[i]);
    }
    cout<<"MAx profit is :";
    cout<<m<<endl;
    return 0;
}