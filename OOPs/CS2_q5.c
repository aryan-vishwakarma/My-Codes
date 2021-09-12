#include<stdio.h>
int count(int a[],int n,int k)
{
    int c=0;
    for(int i=0;i<n;i++)
    if(a[i]==k)
    c++;
    return(c);
}
int notIn(int a[],int p,int k)
{
    int f=1;
    for(int i=0;i<p;i++)
    {
        if(a[i]==k)
        {
            f=0;
            break;
        }
    }
    return(f);
}
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n],a1[n],p=0;
    printf("Enter %d elements of the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(notIn(a1,p,a[i]))
        {
            printf("Frequency of %d is %d\n",a[i],count(a,n,a[i]));
            a1[p]=a[i];
            p++;
        }
    }
}