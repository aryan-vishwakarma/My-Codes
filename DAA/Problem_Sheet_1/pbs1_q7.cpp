#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return ((float)a.first / a.second > (float)b.first / b.second);
}
void sortByQuotient(int *a, int *b, int n)
{
    int i;
    pair<int, int> p[n];
    for (i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = b[i];
    }
    sort(p, p + n, compare);
    for (i = 0; i < n; i++)
    {
        a[i] = p[i].first;
        b[i] = p[i].second;
    }
}
int main()
{
    int n, w, maxV;
    cout << "Enter number of items : ";
    cin >> n;
    int val[n], wgt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of item " << (i + 1) << " : ";
        cin >> val[i];
        cout << "Enter weight of item " << (i + 1) << " : ";
        cin >> wgt[i];
    }
    cout << "Enter weight capacity of knapsack : ";
    cin >> w;
    sortByQuotient(val, wgt, n);
    int i = 0;
    maxV = 0;
    while (i <= n && w > 0)
    {
        if (w < wgt[i])
        {
            maxV += ((float)w / wgt[i]) * val[i];
            break;
        }
        maxV += val[i];
        w -= wgt[i];
        i++;
    }
    cout << "Maximum value of knapsack is " << maxV << endl;
    return 0;
}