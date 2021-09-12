#include<stdio.h>
void pr(int n,int t)
{
    if(n>1)
    {
        if(n%t==0)
        printf("%d ",t);
        else
        pr()
    }
}