#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1],
                                  wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
int main()
{
    int n;
    cout << "Enter number of items : ";
    cin >> n;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of item " << (i + 1) << " : ";
        cin >> val[i];
        cout << "Enter the weight of item " << (i + 1) << " : ";
        cin >> wt[i];
    }
    int W;
    cout << "Enter the maximum weight : ";
    cin >> W;
    cout << "Maximum value that can be obtained = " << knapSack(W, wt, val, n) << endl;
    return 0;
}