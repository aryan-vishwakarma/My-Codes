#include <stdio.h>
int summ(int a, int b)
{
    return (a + b);
}
int main()
{
    int n, i, s = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements of an array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        s = summ(a[i], s);
    printf("Sum is %d", s);
}