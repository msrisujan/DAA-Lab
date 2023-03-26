#include <stdio.h>
int main()
{
    int n, temp, temp1;
    printf("Enter number of activities \n");
    scanf("%d", &n);
    int a[2][n];
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("Enter the start time ofactivities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter the end time of activities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[1][i] > a[1][j])
            {

                temp = a[1][j];
                a[1][j] = a[1][i];
                a[1][i] = temp;

                temp1 = a[0][j];
                a[0][j] = a[0][i];
                a[0][i] = temp1;
            }
        }
    }
    int b[n];
    int x = 0;
    b[0] = 0;
    x++;
    for (int i = 1; i < n; i++)
    {
        if (a[0][i] >= a[1][b[x - 1]])
        {
            b[x] = i;
            x++;
        }
    }
    printf("Actvities that can be done are : \n");

    for (int i = 0; i < x; i++)
    {
        printf(" %d %d \n", a[0][b[i]], a[1][b[i]]);
    }
    return 0;
}

