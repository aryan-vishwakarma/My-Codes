#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a1[n],a2[n],a3[2*n];
    printf("Enter %d elements of 1st array in descending order:\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&a1[i]);
    printf("Enter %d elements of 2nd array in descending order:\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&a2[i]);
    int p1=0,p2=0;
    for(i=0;i<2*n;i++)
    {
        if(p1==n)
        {
            a3[i]=a2[p2];
            p2++;
        }
        else if(p2==n)
        {
            a3[i]=a1[p1];
            p1++;
        }
        else if(a1[p1]>=a2[p2])
        {
            a3[i]=a1[p1];
            p1++;
        }
        else
        {
            a3[i]=a2[p2];
            p2++;
        }
    }
    for(i=0;i<n*2;i++)
    printf("%d ",a3[i]);
}