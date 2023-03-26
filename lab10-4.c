#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int x,int y)
{
    if(x>y)
    return y;
    else
    return x;
}
int solve(int i,int j,char s[])
{
            if ( i >= j)
            return 0;
         if( s[i] == s[j])
            return solve(i + 1, j - 1,s);
          else
            return min(solve(i + 1, j,s), solve(i, j - 1,s)) + 1;
}
int main()
{
    char a[100];
    printf("enter the string\n");
    scanf("%s",a);
int b=solve(0,strlen(a)-1,a);
printf("%d",b);
return 0;
}