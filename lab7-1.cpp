#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m,c;
        cin>>n>>m>>c;
        int team[c];
        int sum=0;
        for(int j=0;j<c;j++)
        {
            cin>>team[j];
            sum=sum+team[j];
        }
        vector<int>v;
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<team[j];k++)
            {
                v.push_back(j+1);
            }
        }
        int a=0;
        for(int j=0;j<n;j++)
        {
            if(a>=sum)
            {
                break;
            }
            for(int k=a;k<a+m;k++)
            {
                cout<<v[k];
            }
            cout<<endl;
            a=a+m;
            if(a>=sum)
            {
                break;
            }
            reverse(v.begin()+a,v.begin()+a+m);
            for(int k=a;k<a+m;k++)
            {
                cout<<v[k];
            }
            cout<<endl;
            a=a+m;
        }
    }
    return 0;
}
