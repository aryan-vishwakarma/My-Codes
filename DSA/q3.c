#include<stdio.h>
void fib(int n)
{
    if(n<1)
    printf("Invalid input.");
    else if(n==1)
    printf("0");
    else if(n==2)
    printf("0  1");
    else
    {
        int s1=0,s2=1;
        int s3;
        printf("0  1  ");
        for(int i=2;i<n;i++)
        {
            s3=s1+s2;
            printf("%d  ",s3);
            s1=s2;
            s2=s3;
        }
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    fib(n);
}