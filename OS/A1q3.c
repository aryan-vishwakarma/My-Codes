#include <stdio.h>
int main()
{
    int n, n1;
    printf("Enter a number: ");
    scanf("%d", &n);
    int rev = 0, sum = 0, d;
    n1 = n;
    while (n > 0)
    {
        d = n % 10;
        sum += d;
        rev = rev * 10 + d;
        n = n / 10;
    }
    printf("Reverse of %d is %d\n", n1, rev);
    printf("Sum of digits of %d is %d\n", n1, sum);
}