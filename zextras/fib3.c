#include <stdio.h>
int fib(int n)
{
    if (n == 1)
        return (1);
    else if (n == 2)
        return (1);
    else
        return (fib(n - 1) + fib(n - 2));
}
void main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int s = fib(n);
    printf("\n%d", s);
}