#include<stdio.h>
int main()
{
    int n1,n2;
    printf("Enter two numbers: ");
    scanf("%d%d",&n1,&n2);
    if((n1^n2)<0)
    printf("Integers have opposite sign.");
    else
    printf("Integers have same sign.");
}