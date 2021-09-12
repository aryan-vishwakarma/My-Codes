#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int g=a[0],p=0;
    for(i=0;i<n-1;i++)
    {
        if(i<p)
        a[i]=g;
        else
        {
            g=a[i+1];
            p=i+1;
            for(j=i+2;j<n;j++)
            {
                if(a[j]>g)
                {
                    g=a[j];
                    p=j;
                }
            }
            a[i]=g;
        }
    }
    a[n-1]=0;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}