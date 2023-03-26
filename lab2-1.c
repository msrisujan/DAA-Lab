#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int arr[n];
    int a,b;
    if(n==1)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",x);
        printf("*");
    }
    else
    {
    scanf("%d %d",&a,&b);
    int min,smin;
    if(a<b)
    {
        min=a;
        smin=b;
    }
    else if(b<a)
    {
        min=b;
        smin=a;
    }
    else if(n==2&&a==b)
    {
        printf("%d\n",min);
        printf("*");
        return;
    }
    else if(a==b && n>2)
    {
        min=smin=a=b;
    }
    for(int i=2;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<min && min!=smin)
        {
            smin=min;
            min=arr[i];
        }
        else if(arr[i]>min && arr[i]<smin && min!=smin)
        {
            smin=arr[i];
        }
        else if(min==smin && arr[i]<min)
        {
            min=arr[i];
        }
        else if(min==smin && arr[i]>min)
        {
            smin=arr[i];
        }
    }
    if(min==smin)
    {
        printf("%d\n",min);
        printf("*");
    }
    else
    {
        printf("%d\n%d",min,smin);
    }
    }
    return 0;
}