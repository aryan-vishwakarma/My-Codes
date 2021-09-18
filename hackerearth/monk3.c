#include <stdio.h>
#include <stdbool.h>
#include <string.h>
_Bool isequal(char a[], char b[])
{
    int f = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
        {
            f = 1;
            return (false);
            break;
        }
    }
    if (f == 0)
        return (true);
}
void checkBiggest(char a[], int n, char b[])
{
    strcpy(b, a);
    for (long i = 0; i < n; i++)
    {
    }
}