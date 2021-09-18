#include <stdio.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
            printf("\t");
        for (j = i; j < 2 * i; j++)
            printf("%d\t", j);
        for (j = 2 * i - 2; j >= i; j--)
            printf("%d\t", j);
        printf("\n");
    }
}