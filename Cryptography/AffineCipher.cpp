#include<iostream>
#include<algorithm>
#include<string.h>
#include<ctype.h>
using namespace std;

int aInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
}

string affineEncrypt(string plain_text, int a, int b)
{
    int pl = plain_text.length();
    string cipher;

    //Changing Plain Text to upper case
    for_each(plain_text.begin(), plain_text.end(), [](char& c) {
        c = ::toupper(c);
        });

    for (int i = 0; i < pl; i++) {
        if (isalpha(plain_text[i])) {
            cipher.push_back('A' + (((plain_text[i] - 'A') * a + b) % 26 + 26) % 26);
        }
        else {
            cipher += plain_text[i];
        }
    }
    return cipher;
}

string affineDecrypt(string cipher, int a, int b)
{
    int cl = cipher.length();
    string plain_text = "";

    //Changing Cipher Text to upper case
    for_each(cipher.begin(), cipher.end(), [](char& c) {
        c = ::toupper(c);
        });

    for (int i = 0; i < cl; i++) {
        if (isalpha(cipher[i])) {
            plain_text += 'A' + (aInverse(a) * (cipher[i] - 'A' - b) % 26 + 26) % 26;
        }
        else {
            plain_text += cipher[i];
        }
    }
    return plain_text;
}

int main() {
    int a, b;
    string plain_text, cipher, plain_text2;
    cout << "Enter plain text : ";
    getline(cin, plain_text, '\n');
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cipher = affineEncrypt(plain_text, a, b);
    plain_text2 = affineDecrypt(cipher, a, b);
    cout << "Cipher text : " << cipher << endl;
    cout << "Deciphered text : " << plain_text2 << endl;
}