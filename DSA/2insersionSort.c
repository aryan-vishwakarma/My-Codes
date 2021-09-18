#include <stdio.h>
void insertionSort(int *a, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void inputArr(int *a, int n)
{
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void displayArr(int *a, int n)
{
    printf("The array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}
int main()
{
    printf("Enter the value of n: ");
    int n;
    scanf("%d", &n);
    int a[n];
    inputArr(a, n);
    displayArr(a, n);
    insertionSort(a, n);
    printf("\nArray is sorted.\n");
    displayArr(a, n);
    return 0;
}