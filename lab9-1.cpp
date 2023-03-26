#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of parts :";
    cin>>n;
    int weight;
    cout<<"Enter total weight :";
    cin>>weight;
    int w[n];
    cout<<"Enter weight of each part"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int e[n];
    for(int i=0;i<n;i++)
    {
        e[i]=w[i];
    }
    sort(w,w+n);
    int wei=0,x[n],m=0;
    for(int i=0;i<n;i++)
    {
        if(wei+w[i]<=weight)
        {
            x[i]=w[i];
            wei=wei+w[i];
            m++;
        }
    }
    int j=0,a[m];
    cout<<"Parts are :";
    while(j<=m)
    {
        for(int i=0;i<n;i++)
        {
            if(x[j]==e[i])
            {
                a[j]=i;
                if(a[j-1]==a[j])
                {
                    a[j]=i+1;
                }
                break;
            }
        }
        j++;
    }
    sort(a,a+m);
    for(int i=0;i<m;i++)
    {
        cout<<a[i]+1<<" ";
    }
    return 0;
}
