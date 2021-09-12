#include <bits/stdc++.h>
using namespace std;
void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")";
}
void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << "\nOptimal Cost is : " << m[1][n - 1];
}
int main()
{
    int n;
    cout << "Enter number of matrices : ";
    cin >> n;
    n++;
    int dims[n];
    cout << "Enter n and m for n*m matrix :\n";
    cin >> dims[0];
    cin >> dims[1];
    for (int i = 2; i < n; i++)
    {
        cout << "Enter m for " << dims[i - 1] << "*m matrix : ";
        cin >> dims[i];
    }
    matrixChainOrder(dims, n);
    return 0;
}