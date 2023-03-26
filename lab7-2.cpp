#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2!=0)
    {
        cout<<"NO";
        return 0;
    }
    int b[n + 1] = { 0 };
    for (int i = 0; i < n; i++)
        b[i + 1] = b[i] + a[i];
    vector<int> subarr;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            subarr.push_back(b[j] - b[i - 1]);
    for(int i=0;i<subarr.size();i++)
    {
        if(subarr[i]==(sum/2))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    
    
    return 0;
}
