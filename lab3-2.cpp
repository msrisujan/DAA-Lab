#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,n,y=0;
    cin>>size;
    n=size;
    int a[size];
    if(size%2!=0)
    {
        size++;
        y=1;
    }
    int x= ceil(size/2);
    int min[x],max[x];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(y==1)
    {
        a[size-1]=a[size-2];
    }
    for(int i=0;i<size;i++)
    {
        if(i%2==0)
        {
            if(a[i]<a[i+1])
            {
                min[(i+1)/2]=a[i];
                max[(i+1)/2]=a[i+1];
            }
            if(a[i]>a[i+1])
            {
                min[(i+1)/2]=a[i+1];
                max[(i+1)/2]=a[i];
            }
            if(a[i]==a[i+1])
            {
                min[(i+1)/2]=a[i];
                max[(i+1)/2]=a[i+1];
            }
        }
    }
    int gmin=min[0];
    int gmax=max[0];
    for(int i=0;i<x;i++)
    {
        if(gmin>min[i])
            gmin=min[i];
        if(gmax<max[i])
            gmax=max[i];
    }
    cout<<gmin<<endl<<gmax<<endl;
    return 0;
}
