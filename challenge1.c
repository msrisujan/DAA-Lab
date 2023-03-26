#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* string(char s1[],char s2[])
{
    int i,j,k=0;
    char *s3;
    s3=(char*)malloc(sizeof(char)*100);
    for(i=0;i<strlen(s1);i++)
    {
        for(j=0;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j])
            {k=0;
                if(strlen(s3)<strlen(s2)-j+i){
                for(int m=0;m<=i;m++)
                {
                    s3[k]=s1[m];
                    k++;
                   
                }
                for(int m=j+1;m<strlen(s2);m++)
                { 
                    s3[k] = s2[m];
                    k++;
                }    
                }   
            }
        }
    }
   return s3;
}

int main() {

    char s1[100];
    char s2[100];
    char* s3;
    char* s4;

    scanf("%s",s1);
    scanf("%s",s2);
  s3=string(s1,s2);
    s4 =string(s2,s1);
   if (strlen(s3)==0 && strlen(s4)==0 )
    printf("*");
    else if(strlen(s4)>strlen(s3)){
        printf("%s\n",s4);
        printf("%ld",strlen(s4));
    }
   else 
        {
    printf("%s\n",s3);
        printf("%ld",strlen(s3));
    }
        
    return 0;
}