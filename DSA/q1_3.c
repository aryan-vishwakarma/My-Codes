#include <stdio.h>
int s;
void fact(int n)
{
    s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return (s);
}
int main()
{
    int n;
    scanf("%d", &n);
    fact(n);
    printf("%d\n", s);
}