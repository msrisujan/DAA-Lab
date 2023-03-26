#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,i,min=0,max=0;
    cin>>size;
    int a[size];
    for(i=0;i<size;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            min=max=a[i];
        }
        if(i>0)
        {
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
    }
    cout<<min<<endl<<max<<endl;
    return 0;
}
