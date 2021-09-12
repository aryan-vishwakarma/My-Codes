#include<stdio.h>
int main()
{
    int n1,n2;
    printf("Enter two numbers: ");
    scanf("%d %d",&n1,&n2);
    int g=n2^((n1^n2)^-(n1<n2));
    int s=n1^((n1^n2)^-(n1<n2));
    printf("Smallest is %d\nGreatest is %d",s,g);
}