#include <bits/stdc++.h>
using namespace std;

void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M)
            cout << "Pattern found at index "
            << i << endl;
    }
}
int main()
{
    char txt[50];
    char pat[50];
    cout << "Enter the text : ";
    cin >> txt;
    cout << "Enter the pattern : ";
    cin >> pat;
    search(pat, txt);
    return 0;
}