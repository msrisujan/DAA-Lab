#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int size;
void deletenum(int arr[],int n)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==n)
        {
            for(int j=i; j<(size-1); j++)
                arr[j] = arr[j+1];
            size--;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    size=n;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=i+1;
    }
    int j=2;
    if(size==1 || size==2)
    {
        printf("1");
        return 0;
    }
    while(size!=0)
    {
        if(size==1)
        {
            printf("%d",arr[0]);
            return 0;
        }
        else if(size==2 && j==1)
        {
            printf("%d",arr[1]);
            return 0;
        }
        else if(size==2)
        {
            printf("%d",arr[0]);
            return 0;
        }
        deletenum(arr,arr[j-1]);
        if(j>=size)
            j=(j+1)%size;
        else
            j=(j+1)%n;
    }
    
    return 0;
}