#include <stdio.h>
#include <math.h>
int main()
{
    int n, g;
    printf("Enter n value: ");
    scanf("%d", &n);
    int l = 2 * n - 1;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            g = i < j ? i : j;
            g = g < l - i ? g : l - i - 1;
            g = g < l - j ? g : l - j - 1;
            printf("%d\t", n - g);
        }
        printf("\n");
    }
}