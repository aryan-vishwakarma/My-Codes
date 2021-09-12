#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

//pairsort template function to sort arrays a and b wrt a
template <class X, class Y>
void pairsort(X *a, Y *b, int n)
{
    int i;
    pair<X, Y> p[n];
    for (i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = b[i];
    }
    sort(p, p + n);
    for (i = 0; i < n; i++)
    {
        a[i] = p[i].first;
        b[i] = p[i].second;
    }
}

int main()
{
    int n, i, res_len = 0;
    cout << "Enter number of activities : ";
    cin >> n;
    int start[n], finish[n], result[n];
    //input from user
    for (i = 0; i < n; i++)
    {
        cout << "Enter start time of activity " << i + 1 << " : ";
        cin >> start[i];
        cout << "Enter finish time of activity " << i + 1 << " : ";
        cin >> finish[i];
    }

    //sorting the data according to finish[]
    pairsort<int, int>(finish, start, n);
    result[0] = 0;
    res_len++;
    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[result[res_len - 1]])
        {
            result[res_len] = i;
            res_len++;
        }
    }
    cout << "The person can perform atmost " << res_len << " activities\n";
    cout << endl;
}