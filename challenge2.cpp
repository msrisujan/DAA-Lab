#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,k,total_sum=0;
    cin>>size>>k;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        total_sum+=arr[i];
    }
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(abs(total_sum-(2*sum))==k)
        {
            cout<<1<<endl;
            for(int j=0;j<i;j++)
            {
                cout<<arr[j]<<endl;
            }
            cout<<2<<endl;
            for(int j=i;j<size;j++)
            {
                cout<<arr[j]<<endl;
            }
            return 0;
        }
        sum+=arr[i];
    }
    cout<<"*";
    return 0;
}