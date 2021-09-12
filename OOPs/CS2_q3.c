#include<stdio.h>
int count(int a[],int n,int k)
{
    int c=0;
    for(int i=0;i<n;i++)
    if(a[i]==k)
    c++;
    return(c);
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    if(count(arr,n,arr[i])==1)
    printf("%d ",arr[i]);
}