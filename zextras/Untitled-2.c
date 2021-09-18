#include <stdio.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int s = 1;
    for (int i = 2; i <= n; i++)
        s *= i;
    return s;
}
void swap(int n[], int p, int limi[], int l)
{
    int t;
    t = n[p];
    n[p] = n[p + 1 + limi[p]];
    n[p + 1 + limi[p]] = t;
    limi[p]++;
    if (limi[p] == l - p)
    {
        limi[p] = 0;
        swap(n, p - 1, limi, l);
    }
}
void dispp(int n[], int l)
{
    for (int i = 0; i < l; i++)
        printf("%d ", n[i]);
    printf("\n");
}
void main()
{
    int n[20], limit[20];
    int l, i, t;
    for (i = 0; i < 20; i++)
        limit[i] = 0;
    printf("How many numbers: ");
    scanf("%d", &l);
    for (i = 0; i < l; i++)
        scanf("%d", &n[i]);
    for (i = 0; i < fact(l); i++)
    {
        dispp(n, l);
        t = n[l - 1];
        n[l - 1] = n[l - 2];
        n[l - 2] = t;
        limit[l - 2]++;
        if (limit[l - 2] == 2)
        {
            swap(n, l - 3, limit, l);
            limit[l - 2] = 0;
        }
    }
}
