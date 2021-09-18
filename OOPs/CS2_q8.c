#include <stdio.h>
int main()
{
    int n, i, j, t;
    int a[10][10];
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the elements in the matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    printf("The transpose of the matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d  ", a[i][j]);
        printf("\n");
    }
    return 0;
}