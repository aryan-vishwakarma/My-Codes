#include<stdio.h>
void Search(int a[10][10],int n,int k)
{
    int i=0,j=n-1,f=0;
    while(i<n&&j>=0)
    {
        if(a[i][j]==k)
        {
            printf("The element found at the position in the matrix is:  %d, %d",i,j);
            f=1;
            break;
        }
        if(a[i][j]>k)
        j--;
        else 
        i++;
    }
    if(f==0)
    printf("Element not found.");
}
int main()
{
    int n,i,j,k;
    int a[10][10];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter the elements of row and column wise sorted matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Enter the element to be searched: ");
    scanf("%d",&k);
    Search(a,n,k);
}
