// A C++ program to find minimum possible
// time by the car chassis to complete
#include <bits/stdc++.h>
using namespace std;
int n;
int min(int a, int b)
{
    return a < b ? a : b;
}

int carAssembly(int a1[], int a2[], int t1[], int t2[], int *e, int *x)
{
    int T1[n], T2[n], i;
    T1[0] = e[0] + a1[0];
    T2[0] = e[1] + a2[0];
    for (i = 1; i < n; ++i)
    {
        T1[i] = min(T1[i - 1] + a1[i],
                    T2[i - 1] + t2[i] + a1[i]);
        T2[i] = min(T2[i - 1] + a2[i],
                    T1[i - 1] + t1[i] + a2[i]);
    }
    return min(T1[n - 1] + x[0],
               T2[n - 1] + x[1]);
}
int main()
{
    cout << "Enter value of n : ";
    cin >> n;
    int a1[n], a2[n], t1[n], t2[n], e[2], x[2];
    cout << "Enter a1 values :\n";
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    cout << "Enter a2 values :\n";
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    t1[0] = 0;
    t2[0] = 0;
    cout << "Enter t1 values :\n";
    for (int i = 1; i < n; i++)
        cin >> t1[i];
    cout << "Enter t2 values :\n";
    for (int i = 1; i < n; i++)
        cin >> t2[i];
    cout << "Enter e1 : ";
    cin >> e[0];
    cout << "Enter e2 : ";
    cin >> e[1];
    cout << "Enter x1 : ";
    cin >> x[0];
    cout << "Enter x2 : ";
    cin >> x[1];

    cout << "Minimun time = " << carAssembly(a1, a2, t1, t2, e, x) << endl;

    return 0;
}