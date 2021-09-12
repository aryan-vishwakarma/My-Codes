#include<stdio.h>
void main()
{
    int s1=1,s2=1,s3=2,n,t;
    printf("Enter n: ");
    scanf("%d",&n);
    if(n==1)
    printf("1");
    else if(n==2)
    printf("1");
    else if(n>2)
    {
        printf("1 1 ");//for nth term only, remove this
        for(int i=3;i<=n;i++)
        {
            s3=s1+s2;
            printf("%d ",s3);//for nth term only, remove this
            t=s2;
            s2=s3;
            s1=t;
        }
        //printf("%d",s3);//for nth term only, add this
    }
    else
    printf("Invalid Input...");
}