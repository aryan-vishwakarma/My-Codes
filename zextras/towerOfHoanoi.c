#include <stdio.h>
void toh(int n, char fr, char to, char bfr)
{
    if (n == 1)
    {
        printf("Move a ring from %c to %c\n", fr, to);
    }
    else
    {
        toh(n - 1, fr, bfr, to);
        printf("Move a ring from %c to %c\n", fr, to);
        toh(n - 1, bfr, to, fr);
    }
}
int main()
{
    printf("Enter the value of n: ");
    int n;
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}