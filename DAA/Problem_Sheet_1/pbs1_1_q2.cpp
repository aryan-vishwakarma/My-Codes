/*
Question
Counting inversions
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array 
is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count 
is the maximum. Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] 
and i < j.
Example: Input: arr[] = {8, 4, 2, 1}
Output: 6. The six inversions: (8,4), (4,2), (8,2), (8,1), (4,1), (2,1).
Input: arr[] = {3, 1, 2}
Output: 2. The two inversions: (3,1), (3,2).
*/
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