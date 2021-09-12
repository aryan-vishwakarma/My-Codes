#include <iostream>
using namespace std;
int main()
{
    int n, i, j, count = 0;
    cout << "Enter number of elements : ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                count++;
        }
    }
    cout << "No. of inversions : " << count << endl;
}