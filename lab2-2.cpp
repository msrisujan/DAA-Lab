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
    if(n==1)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",x);
        printf("*");
        return 0;
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",x);
        printf("*");
        return 0;
    }
    sort(a,a+n);
    if(a[0]!=a[1])
    {
        printf("%d\n%d",a[0],a[1]);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(a[0]!=a[i])
        {
            printf("%d\n%d",a[0],a[i]);
            return 0;
        }
    }
    printf("%d\n",a[0]);
    printf("*");
    }
    
    return 0;
}
