#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;

class VigenereCipher
{

private:

    char alpha[26][26];

public:

    VigenereCipher() {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                alpha[i][j] = 'A' + (i + j) % 26;
            }
        }
    }

    string encrypt(string plain_text, string key)
    {
        int len_plain = plain_text.length();
        int len_key = key.length();

        string cipher;

        //Changing Plain Text to upper case
        for_each(plain_text.begin(), plain_text.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Expanding the key to fit length of the plain text
        if (len_key < len_plain) {
            for (int i = 0; i < len_plain - len_key; i++) {
                key.push_back(key[i]);
            }
        }

        for (int i = 0; i < len_plain; i++) {
            if (isalpha(plain_text.at(i))) {
                cipher.push_back(alpha[plain_text.at(i) - 'A'][key.at(i) - 'A']);
            }
            else {
                cipher.push_back(plain_text.at(i));
            }
        }

        return cipher;
    }

    string decrypt(string cipher, string key)
    {
        int len_cipher = cipher.length();
        int len_key = key.length();

        string plain_text;

        //Changing Cipher to upper case
        for_each(cipher.begin(), cipher.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Changing Key to upper case
        for_each(key.begin(), key.end(), [](char& c) {
            c = ::toupper(c);
            });

        //Expanding the key to fit the length of cipher text
        if (len_key < len_cipher) {
            for (int i = 0; i < len_cipher - len_key; i++) {
                key.push_back(key[i]);
            }
        }

        for (int i = 0; i < len_cipher; i++) {
            if (isalpha(cipher.at(i))) {
                plain_text.push_back(alpha[(cipher.at(i) - key.at(i) + 26) % 26][0]);
            }
            else {
                plain_text.push_back(cipher.at(i));
            }
        }

        return plain_text;
    }
    
};

int main(int argc, char* argv[])
{
    VigenereCipher v;
    string plain_text, key, cipher, plain2;
    cout << "Enter plain text : ";
    getline(cin, plain_text);
    cout << "Enter key : ";
    cin >> key;
    cipher = v.encrypt(plain_text, key);
    cout << "Cipher Text is : " << cipher << endl;
    plain2 = v.decrypt(cipher, key);
    cout << "On deciphering the cipher text : " << plain2 << endl;
}