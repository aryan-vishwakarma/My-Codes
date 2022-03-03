#include<iostream>
#include<algorithm>
using namespace std;

class VernamCipher
{
public:
    static string encrypt(string plain_text, string key)
    {
        int pl = plain_text.length();
        int kl = key.length();

        string cipher;
        
        if (pl == kl)
        {
            //Changing Plain Text to upper case
            for_each(plain_text.begin(), plain_text.end(), [](char& c) {
                c = ::toupper(c);
                });

            //Changing Key to upper case
            for_each(key.begin(), key.end(), [](char& c) {
                c = ::toupper(c);
                });
            
            for (int i = 0; i < pl; i++) {
                if (isalpha(plain_text[i])) {
                    cipher.push_back('A' + (plain_text.at(i) - 'A' + key.at(i) - 'A') % 26);
                }
                else if (plain_text[i] == ' ') {
                    cipher.push_back('|');
                }
                else {
                    cipher.push_back(plain_text[i]);
                }
            }
        }
        return cipher;
    }

    static string decrypt(string cipher, string key)
    {
        int cl = cipher.length();
        int kl = key.length();

        string plain_text;

        if (cl == kl)
        {
            //Changing Cipher to upper case
            for_each(cipher.begin(), cipher.end(), [](char& c) {
                c = ::toupper(c);
                });

            //Changing Key to upper case
            for_each(key.begin(), key.end(), [](char& c) {
                c = ::toupper(c);
                });
            
            for (int i = 0; i < cl; i++) {
                if (isalpha(cipher[i])) {
                    plain_text.push_back('A' + (cipher.at(i) - key.at(i) + 26) % 26);
                }
                else if (cipher[i] == '|') {
                    plain_text.push_back(' ');
                }
                else {
                    plain_text.push_back(cipher[i]);
                }
            }
        }
        return plain_text;
    }
};

int main() {
    string plain_text, key;
    cout << "Enter the plain text : ";
    getline(cin, plain_text);
    cout << "Enter the key : ";
    cin >> key;
    string cipher = VernamCipher::encrypt(plain_text, key);
    if (cipher.length() != 0) {
        cout << "Cipher text is : " << cipher << endl;
        string plain_text2 = VernamCipher::decrypt(cipher, key);
        cout << "On decrypting : " << plain_text2 << endl;
    }
    else {
        cout << "Length of key does not match with the length of text\n";
    }
}