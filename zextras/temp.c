#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    printf("Hello\n");
    int a = 0;
    while (true)
    {
        while (a == 2)
            ;
        printf("Value of a : %d\n", a);
        a++;
    }
    return 0;
}