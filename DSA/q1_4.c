#include<stdio.h>
int n;
int s;
void fact()
{
    s=1;
    for(int i=1;i<=n;i++)
    s*=i;
}
int main()
{
    scanf("%d",&n);
    fact();
    printf("%d\n",s);
}