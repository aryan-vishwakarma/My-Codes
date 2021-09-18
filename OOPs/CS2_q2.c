#include <stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n], i, j, c = 0;
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                c++;
                break;
            }
        }
    }
    printf("Total duplicate numbers= %d", c);
}