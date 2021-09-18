#include <stdio.h>
#include <stdbool.h>
bool binarySearch(int *a, int n, int item, int *index)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (item > a[mid])
            left = mid + 1;
        else if (item < a[mid])
            right = mid - 1;
        else
        {
            item = a[mid];
            *index = mid;
            return true;
        }
    }
    return false;
}
void inputArr(int *a, int n)
{
    printf("Enter %d values in ascending order:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
int main()
{
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    inputArr(a, n);
    printf("\nEnter the value to be searched: ");
    scanf("%d", &k);
    int p;
    if (binarySearch(a, n, k, &p))
        printf("\n%d found at index: %d\n", k, p);
    else
        printf("\n%d not found in the Array.\n", k);
}