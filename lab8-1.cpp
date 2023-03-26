#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cout<<"enter the value :";
    cin>>n;
    cout<<"enter no of denominations :";
    cin>>k;
    int a[k];
    cout<<"enter the denominations :";
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    sort(a,a+k);
    vector<int>vec;
    for(int i=k-1;i>=0;i--)
    {
        while(n>=a[i])
        {
            n-=a[i];
            vec.push_back(a[i]);
        }
    }
    cout<<"coins to give :";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    cout<<"no of coins : ";
    cout<<vec.size();
    return 0;
}
//this will work for all cases when the denominations are in AP(arthematic progression)
//and it will fail in other cases like if 1 3 4 are coins and for change of 6 then with this logic output will be 3(4+1+1)
//but correct should be 2 which is 3+3