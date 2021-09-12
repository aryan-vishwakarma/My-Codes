#include<stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n],i,s,g;
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    g=a[0];
    s=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>g)
        g=a[i];
        else if(a[i]<s)
        s=a[i];
    }
    printf("%d is smallest\n%d is greatest",s,g);
}