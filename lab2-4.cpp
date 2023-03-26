#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void bubble_sort(int a[],int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
        cout << a[i] << endl;
}

int main() {
    int n;
    cin>>n;
    int asize[n];
    int arr[987654];
    int count = 0;
    for(int i=0;i<n;i++)
    {
        cin>>asize[i];
        for(int j=0;j<asize[i];j++)
        {
            int x;
            cin>>x;
            arr[count] = x;
            count++;
        }
    }
    bubble_sort(arr,count);
    return 0;
}