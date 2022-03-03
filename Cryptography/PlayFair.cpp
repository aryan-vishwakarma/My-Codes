#include<iostream>
#include<algorithm>

using namespace std;

class PlayFair
{
    char matrix[5][5];

    bool isInKey(string key, char ch) {
        for (int i = 0; i < key.length(); i++) {
            if (ch == key.at(i)) {
                return true;
            }
        }
        return false;
    }

    bool isInKeyBefore(string key, char ch, int index) {
        for (int i = 0; i < index; i++) {
            if (ch == key.at(i)) {
                return true;
            }
        }
        return false;
    }

    //key is assumed to be in all caps
    //and in 'J' is already replaced with 'I'
    void fillMatrix(string key)
    {
        int k = 0;
        int l = key.length();

        for (int i = 0; i < l; i++) {
            if (!isInKeyBefore(key, key.at(i), i)) {
                matrix[k / 5][k % 5] = key[i];
                k++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (i == 9) continue; //ignoring j since i is taken into account
            if (!isInKey(key, ('A' + i))) {
                matrix[k / 5][k % 5] = 'A' + i;
                k++;
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void findInMatrix(char ch, int& i, int& j) {
        for (i = 0; i < 5; i++) {
            int f = 0;
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == ch) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
    }

public:

    void check(string key) {
        fillMatrix(key);
        displayMatrix();
    }

    string encrypt(string plain_text, string key)
    {
        int pl = plain_text.length();
        int kl = key.length();

        string cipher;

        //Replacing 'J' with 'I'
        for (int i = 0; i < pl; i++) {
            if (plain_text[i] == 'J') {
                plain_text[i] = 'I';
            }
        }
        for (int i = 0; i < kl; i++) {
            if (key[i] == 'J') {
                key[i] = 'I';
            }
        }

        //Changing Plain Text to upper case
        for_each(plain_text.begin(), plain_text.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });

        fillMatrix(key);

        //Adding 'X' when same chars are in a pair
        for (int i = 0; i < pl - 1; i += 2) {
            if (plain_text[i] == plain_text[i + 1]) {
                plain_text.insert(i, 1, 'X');
                pl++;
            }
        }

        //Adding 'X' at the end when the length is odd
        if (pl % 2 == 1) {
            plain_text.push_back('X');
        }

        for (int i = 0; i < pl; i += 2) {
            int r1, r2, c1, c2;
            findInMatrix(plain_text[i], r1, c1);
            findInMatrix(plain_text[i + 1], r2, c2);

            //In case of rectangle
            if (r1 != r2 && c1 != c2) {
                cipher.push_back(matrix[r1][c2]);
                cipher.push_back(matrix[r2][c1]);
            }

            //In case os same row
            else if (r1 == r2) {
                cipher.push_back(matrix[r1][(c1 + 1) % 5]);
                cipher.push_back(matrix[r1][(c2 + 1) % 5]);
            }

            //In case of same column
            else {
                cipher.push_back(matrix[(r1 + 1) % 5][c1]);
                cipher.push_back(matrix[(r2 + 1) % 5][c1]);
            }
        }
        return cipher;
    }

    string decrypt(string cipher, string key)
    {
        int cl = cipher.length();
        int kl = key.length();

        string plain_text;

        //Replacing 'J' with 'I'
        for (int i = 0; i < kl; i++) {
            if (key[i] == 'J') {
                key[i] = 'I';
            }
        }

        //Changing Cipher Text to upper case
        for_each(cipher.begin(), cipher.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });

        fillMatrix(key);

        for (int i = 0; i < cl; i += 2) {
            int r1, r2, c1, c2;
            findInMatrix(cipher[i], r1, c1);
            findInMatrix(cipher[i + 1], r2, c2);

            //In case of rectangle
            if (r1 != r2 && c1 != c2) {
                plain_text.push_back(matrix[r1][c2]);
                plain_text.push_back(matrix[r2][c1]);
            }

            //In case os same row
            else if (r1 == r2) {
                plain_text.push_back(matrix[r1][(c1 + 4) % 5]);
                plain_text.push_back(matrix[r1][(c2 + 4) % 5]);
            }

            //In case of same column
            else {
                plain_text.push_back(matrix[(r1 + 4) % 5][c1]);
                plain_text.push_back(matrix[(r2 + 4) % 5][c1]);
            }
        }

        int pl = plain_text.length();
        for (int i = 0; i < pl; i++) {
            if (plain_text[i] == 'I') {
                plain_text.replace(i, 1, "I/J");
                pl += 3;
                i += 2;
            }
        }
        return plain_text;
    }
};

int main() {
    string key;
    string plain_text;
    cout << "Enter plain text : ";
    cin >> plain_text;
    cout << "Enter the key : ";
    cin >> key;
    PlayFair p;
    string cipher = p.encrypt(plain_text, key);
    cout << "Cipher Text : " << cipher << endl;
    cout << "Plain Text after decipherment : " << p.decrypt(cipher, key);
}