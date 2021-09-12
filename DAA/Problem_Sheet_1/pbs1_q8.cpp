#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMaxActivites(pair<int, int> *activities, int n)
{
    sort(activities, activities + n,
         [](pair<int, int> &x, pair<int, int> &y)
         {
             return x.first < y.first;
         });
    vector<int> L(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (activities[j].second <= activities[i].first && L[i] < L[j])
            {
                L[i] = L[j];
            }
        }
        L[i]++;
    }
    return *max_element(L.begin(), L.end());
}
int main()
{
    int n, i;
    cout << "Enter number of activities : ";
    cin >> n;
    pair<int, int> activities[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter start time of activity " << i + 1 << " : ";
        cin >> activities[i].first;
        cout << "Enter finish time of activity " << i + 1 << " : ";
        cin >> activities[i].second;
    }

    cout << "The maximum number of non-conflicting activities is "
         << findMaxActivites(activities, n);

    return 0;
}