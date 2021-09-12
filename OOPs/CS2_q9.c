#include<stdio.h>
int main()
{
    int n,i,j,t;
    int a[10][10];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter the elements in the matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Lower triangular matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            printf("%d  ",a[i][j]);
            else
            printf("0  ");
        }
        printf("\n");
    }
    return 0;
}