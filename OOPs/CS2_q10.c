#include <stdio.h>
float deter(float a[3][3])
{
    int j, k;
    float s, p;
    for (int i = 0; i < 3; i++)
    {
        p = 1;
        for (j = 0; j < 3; j++)
        {
            if (i + j < 3)
                p *= a[i + j][j];
            else
                p *= a[i + j - 3][j];
        }
        s += p;
        p = 1;
        k = 0;
        for (j = 2; j >= 0; j--)
        {
            if (i + k < 3)
                p *= a[i + k][j];
            else
                p *= a[i + k - 3][j];
            k++;
        }
        s -= p;
    }
    return (s);
}
int main()
{
    int i, j;
    float a[3][3];
    printf("Enter the elements in the matrix:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%f", &a[i][j]);
    printf("Determinant is %f", deter(a));
}
