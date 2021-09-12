#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Elements in forward direction:\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    printf("\nElements in reverse direction:\n");
    for(i=n-1;i>=0;i--)
    printf("%d  ",a[i]);
}