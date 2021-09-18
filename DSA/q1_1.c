#include <stdio.h>
int fact(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return (s);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
}