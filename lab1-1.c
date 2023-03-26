#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int size,z;
    scanf("%d",&size);
    scanf("%d",&z);
    int a[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[i]+a[j]==z)
            {
                printf("%d\n%d\n",a[i],a[j]);
                return 0;
            }
        }
    }
printf("*");
}
