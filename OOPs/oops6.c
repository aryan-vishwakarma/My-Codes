#include <stdio.h>
int main()
{
    unsigned int n, rn = 0;
    int t;
    printf("Enter n: ");
    scanf("%u", &n);
    int l = 8 * sizeof(n);
    for (int i = 0; i < l; i++)
    {
        t = n & (1 << i);
        if (t)
        {
            rn = rn | (1 << (l - 1 - i));
        }
    }
    printf("%u", rn);
}