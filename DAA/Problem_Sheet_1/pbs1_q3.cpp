#include <stdbool.h>
#include <iostream>
using namespace std;
_Bool isIncreasing(int *a, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
_Bool isDecreasing(int *a, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (a[i] < a[i + 1])
            return false;
    }
    return true;
}
void calc(int *a, int n)
{
    int f = 0;
    cout << "k : ";
    for (int k = 0; k < n; k++)
    {
        if (isIncreasing(a, 0, k) && isDecreasing(a, k + 1, n - 1))
        {
            cout << k << " ";
            f = 1;
        }
    }
    if (f == 0)
        cout << "No Possible value for k";
    cout << endl;
}
int main()
{
    int n, i;
    cout << "Enter number of elements for the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    //inputting the array
    for (i = 0; i < n; i++)
        cin >> a[i];
    calc(a, n);
}