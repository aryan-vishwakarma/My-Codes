#include <bits/stdc++.h>
#include<math.h>
using namespace std;

class HillCipher {
    static const int MAX = 5;

    void transposeOfMatrix(int matrix[MAX][MAX], int m, int n, int transpose[MAX][MAX]) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
    }

    int determinantOfMatrix(int matrix[MAX][MAX], int n) {
        if (n == 1)
            return (matrix[0][0]);
        int a1[MAX][MAX], d = 0.0;
        int i2, j2;
        for (int i = 0; i < n; i++) {
            i2 = 0;
            j2 = 0;
            for (int i1 = 1; i1 < n; i1++) {
                for (int j1 = 0; j1 < n; j1++) {
                    if (j1 == i)
                        continue;
                    a1[i2][j2] = matrix[i1][j1];
                    if (j2 == n - 2) {
                        j2 = 0;
                        i2++;
                    }
                    else
                        j2++;
                }
            }
            if (i % 2 == 0)
                d += matrix[0][i] * determinantOfMatrix(a1, n - 1);
            else
                d -= matrix[0][i] * determinantOfMatrix(a1, n - 1);
        }
        return (d);
    }

    int cofactor(int matrix[MAX][MAX], int m, int row, int col) {
        int minor[MAX][MAX];
        int r, c;
        c = -1;
        r = 0;
        for (int i = 0; i < m; i++) {
            if (i == row) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                if (j == col) {
                    continue;
                }
                if (c == m - 2) {
                    minor[++r][0] = matrix[i][j];
                    c = 0;
                }
                else {
                    minor[r][++c] = matrix[i][j];
                }
            }
        }
        return(pow(-1, row + col) * determinantOfMatrix(minor, m - 1));
    }

    void adjMatrix(int matrix[MAX][MAX], int m, int adj[MAX][MAX]) {
        int cof_matrix[MAX][MAX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cof_matrix[i][j] = cofactor(matrix, m, i, j);
            }
        }
        transposeOfMatrix(cof_matrix, m, m, adj);
    }
    int multiply(int a[MAX][MAX], int b[MAX][MAX], int ai, int aj, int bi, int bj, int ab[MAX][MAX])
    {
        if (aj == bi)
        {
            for (int i = 0; i < ai; i++)
                for (int j = 0; j < bj; j++)
                {
                    ab[i][j] = 0;
                    for (int c = 0; c < aj; c++)
                        ab[i][j] += b[c][j] * a[i][c];
                }
            return 1;
        }
        else
            return 0;
    }

    void matrixMod26(int mat[MAX][MAX], int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = (mat[i][j] % 26 + 26) % 26;
            }
        }
    }
    int dInverse(int d) {
        for (int i = 1; i < 26; i++) {
            if ((d * i) % 26 == 1) {
                return i;
            }
        }
        return -9999;
    }

public:
    string encrypt(string plain_text, string key) {
        int pl = plain_text.length();
        int kl = key.length();
        int m = ceil(sqrt(kl));

        //Changing Plain Text to upper case
        for_each(plain_text.begin(), plain_text.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });

        
        int mkey[MAX][MAX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i * m + j < kl) {
                    mkey[i][j] = key.at(i * m + j) - 'A';
                }
                else {
                    //filling X in case key is short
                    mkey[i][j] = 'X' - 'A';
                }
            }
        }

        for (int i = 0; i < pl % m; i++) {
            plain_text.push_back('X');
        }
        string cipher;
        for (int i = 0; i < pl; i += m) {
            int a[MAX][MAX];
            for (int j = i; j < i + m; j++) {
                a[j - i][0] = plain_text.at(j) - 'A';
            }
            int ab[MAX][MAX];
            multiply(mkey, a, m, m, m, 1, ab);
            matrixMod26(ab, m, 1);
            for (int j = 0; j < m; j++) {
                cipher.push_back(ab[j][0] + 'A');
            }
        }
        return cipher;
    }
    string decrypt(string cipher, string key) {
        int cl = cipher.length();
        int kl = key.length();
        int m = ceil(sqrt(kl));

        //Changing Cipher to upper case
        for_each(cipher.begin(), cipher.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });
        
        int mkey[MAX][MAX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i * m + j < kl) {
                    mkey[i][j] = key.at(i * m + j) - 'A';
                }
                else {
                    mkey[i][j] = 'X' - 'A';
                }
            }
        }
        int d = (determinantOfMatrix(mkey, m) % 26 + 26) % 26;
        int adj[MAX][MAX];
        adjMatrix(mkey, m, adj);
        matrixMod26(adj, m, m);
        int dinv = dInverse(d);
        int key_inv[MAX][MAX];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                key_inv[i][j] = ((adj[i][j] * dinv) % 26 + 26)%26;
            }
        }
        string plain;
        for (int i = 0; i < cl; i += m) {
            int a[MAX][MAX];
            for (int j = i; j < i + m; j++) {
                a[j - i][0] = cipher.at(j) - 'A';
            }
            int ab[MAX][MAX];
            multiply(key_inv, a, m, m, m, 1, ab);
            matrixMod26(ab, m, 1);
            for (int j = 0; j < m; j++) {
                plain.push_back(ab[j][0] + 'A');
            }
        }
        return plain;
    }
};

int main() {
    string plain, key;
    cout << "Enter plain text : ";
    cin >> plain;
    cout << "Enter key : ";
    cin >> key;
    HillCipher h;
    string cipher = h.encrypt(plain, key);
    cout << "Cipher text = " << cipher << endl;
    string plain2 = h.decrypt(cipher, key);
    cout << "\nOn decrypting cipher text : " << plain2 << endl;
    return 0;
}