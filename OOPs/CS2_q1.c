#include <stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr1[n], arr2[n], i;
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (i = 0; i < n; i++)
        arr2[i] = arr1[i];
    for (i = 0; i < n; i++)
        printf("%d ", arr2[i]);
}