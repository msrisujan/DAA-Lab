#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter number of classes :";
    cin>>n;
    cout<<"Enter number of lectures :";
    cin>>m;
    int lec[m][2];
    vector<pair<int,int>>time;
    cout<<"Enter lecture timings of each class :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>lec[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        time.push_back({lec[i][0],1});
        time.push_back({lec[i][1],-1});
    }
    sort(time.begin(),time.end());
    int k=0,temp=0;
    for(int i=0;i<time.size();i++)
    {
        temp+=time[i].second;
        k=max(k,temp);
    }
    if(k>n)
    {
        cout<<"NOT POSSIBLE";
    }
    else
    {
        cout<<"Minimum no of class is : "<<k;
    }
    return 0;
}