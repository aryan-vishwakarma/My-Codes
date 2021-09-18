#include <stdio.h>
int n;
int fact()
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return (s);
}
int main()
{
    scanf("%d", &n);
    printf("%d\n", fact());
}