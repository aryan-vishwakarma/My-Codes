#include <stdio.h>
int main()
{
    int T, N, K, i, j;
    int a[100000], a1[100000];
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &K);
        for (j = 0; j < N; j++)
            scanf("%d", &a[j]);
        K = K % N;
        for (j = 0; j < N; j++)
        {
            if (j - K >= 0)
                a1[j] = a[j - K];
            else
                a1[j] = a[j - K + N];
        }
        for (j = 0; j < N; j++)
            printf("%d ", a1[j]);
        printf("\n");
    }
    return 0;
}