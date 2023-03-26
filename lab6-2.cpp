#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m=1;
    cin>>n;
    while(m<=n)
    {
        m=m*2;
    }
    cout<<2*(n-(m/2))+1;
    return 0;
}