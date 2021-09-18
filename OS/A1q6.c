#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Mathematical Table of %d is:\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", n * i);
    }
    return 0;
}