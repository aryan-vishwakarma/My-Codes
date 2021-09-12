#include<stdio.h>
void main()
{
    int a[20][20],n,c=0,i,row=0,col=0;
    printf("Enter n: ");
    scanf("%d",&n);
    int up=0,down=0,right=0,left=0;
    printf("Enter %d numbers:\n",n*n);
    while(c<n*n)
    {
        for(i=left;i<n-right;i++)
        {
            scanf("%d",&a[row][col]);
            col++;
            c++;
        }
        up++;
        col--;
        row++;
        for(i=up;i<n-down;i++)
        {
            scanf("%d",&a[row][col]);
            row++;
            c++;
        }
        right++;
        row--;
        col--;
        for(i=right;i<n-left;i++)
        {
            scanf("%d",&a[row][col]);
            col--;
            c++;
        }
        down++;
        col++;
        row--;
        for(i=down;i<n-up;i++)
        {
            scanf("%d",&a[row][col]);
            row--;
            c++;
        }
        left++;
        row++;
        col++;
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
}