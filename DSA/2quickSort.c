void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int *a, int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
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
    quickSort(a, 0, n - 1);
    printf("Array is sorted.\n");
    displayArr(a, n);
    return 0;
}