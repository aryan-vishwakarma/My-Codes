#include <stdio.h>
int multiply(float a[20][20], float b[20][20], int ai, int aj, int bi, int bj, float ab[20][20])
{
    if (aj == bi)
    {
        for (int i = 0; i < ai; i++)
            for (int j = 0; j < bj; j++)
            {
                ab[i][j] = 0;
                for (int c = 0; c < aj; c++)
                    ab[i][j] += b[c][j] * a[i][c];
            }
        return 1;
    }
    else
        return 0;
}
void inputMat(float a[20][20], int ai, int aj)
{
    for (int i = 0; i < ai; i++)
        for (int j = 0; j < aj; j++)
            scanf("%f", &a[i][j]);
}
void printMat(float a[20][20], int ai, int aj)
{
    for (int i = 0; i < ai; i++)
    {
        for (int j = 0; j < aj; j++)
            printf("%f\t", a[i][j]);
        printf("\n");
    }
}
int main()
{
    printf("Enter dimentions of matrix A in the form M N: ");
    int ai, aj, bi, bj;
    float a[20][20], b[20][20], ab[20][20];
    scanf("%d %d", &ai, &aj);
    printf("Enter the elements in matrix A:\n");
    inputMat(a, ai, aj);
    printf("Enter dimentions of matrix B in the form M N: ");
    scanf("%d %d", &bi, &bj);
    printf("Enter the elements in matrix B:\n");
    inputMat(b, bi, bj);
    if (multiply(a, b, ai, aj, bi, bj, ab) == 0)
        printf("Matrices can't be multiplied.");
    else
        printMat(ab, ai, bj);
    return 0;
}