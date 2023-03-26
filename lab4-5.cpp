#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    int three_way_search(int array[], int x, int low, int high) {
  if (high >= low) {
    int t1 = low + (high - low) / 3;
    int t2=t1+(high - low) / 3;
    if (array[t1] == x)
    {
        return t1;
    }  
    if(array[t2]==x)
    {
        return t2;
    }     
    if (array[t1] > x)
    {
        return three_way_search(array, x, low, t1 - 1);
    }
    if(array[t2]>x)
    {
        return three_way_search(array, x, t1, t2-1);
    }
    return three_way_search(array, x, t2+1,high);
  }
  return -1;
}

int main() {
    int n,x;
    cin>>n;
    cin>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m=three_way_search(a,x,0,n-1);
    if(m==-1)
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}
