#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
using namespace std;
void lcs(char* X, char* Y, char* lcs)
{
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (tolower(X[i - 1]) == tolower(Y[j - 1]))
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    // char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (tolower(X[i - 1]) == tolower(Y[j - 1]))
        {
            lcs[index - 1] = tolower(X[i - 1]);
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
}
int main() {
    char data[][20] = { "Google", "Amazon", "Microsoft", "Allenorgan", "Zomato", "Flipkart", "Adobe", "Maruthi", "Mercedes", "Loreal" };
    char X[20];
    cout << "Enter X : ";
    cin >> X;
    int p = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(X, data[i]) == 0) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << X << " is not int the database\n";
    }
    else {
        char str[20];
        int max = 0;
        int l = 0;
        for (int i = 0; i < 10; i++) {
            if (i == p) {
                continue;
            }
            else {
                lcs(data[i], X, str);
                cout << "Y" << i << " = " << data[i] << "," << " LCS(X, Y" << i << ") = " << str << endl;
                l = strlen(str);
                if (l > max) {
                    max = l;
                }
            }
        }
        cout << "Maximum length = " << max << endl;
    }
    
}