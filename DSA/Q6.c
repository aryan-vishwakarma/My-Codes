#include <stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n], i, s = 0;
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        s += a[i];
    printf("Sum of all the elements is: %d", s);
}