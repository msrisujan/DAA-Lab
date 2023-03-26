#include <stdio.h>
int main()
{
    int m, n, temp;
    printf("enter no.of denominations\n");
    scanf("%d", &m);
    int b[m];
    printf("enter the denominations\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i; j < m; j++)
        {
            if (b[i] > b[j])
            {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
    printf("enter the amount\n");
    scanf("%d", &n);
    int c[n + 1];
    for (int i = 0; i < n + 1; i++)
        c[i] = i;
    int a[m][n + 1];
    for (int i = 0; i < m; i++)
        a[i][0] = 1;
    for (int i = 0; i < n + 1; i++)
    {
        if (c[i] % b[0] == 0)
            a[0][i] = 1;
        else
            a[0][i] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (b[i] > c[j])
            {
                a[i][j] = a[i - 1][j];
            }

            else
            {
                a[i][j] = a[i - 1][j] + a[i][j - b[i]];
            }
        }
    }
    printf("no.of ways to give the change=%d", a[m - 1][n]);
}

//There exists overlapping subproblems. yes, it has a DP approach. 
