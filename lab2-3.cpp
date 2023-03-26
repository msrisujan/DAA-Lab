#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k;
    cin>>k;
    int n;
    int a;
    vector<int>arr;
    for(int i=0;i<k;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            arr.push_back(a);
        }
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}