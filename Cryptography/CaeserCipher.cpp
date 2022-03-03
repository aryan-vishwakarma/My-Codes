#include <bits/stdc++.h>
using namespace std;

string encrypt(string str, int skip) {
    int len = str.length();
    string str1 = "";
    for (int i = 0; i < len; i++) {
        str1.push_back((char)('A' + (str.at(i) + skip - 'A') % 26));
    }
    return str1;
}
string decrypt(string str, int skips) {
    int len = str.length();
    string str1 = "";
    for (int i = 0; i < len; i++) {
        str1.push_back((char)('A' + (str.at(i) - skips - 'A' + 26) % 26));
    }
    return str1;
}
int main() {
    string str;
    int skips;
    cout << "Enter the string : ";
    cin >> str;
    cout << "Enter skips : ";
    cin >> skips;
    if (skips <= 25) {
        string str1 = encrypt(str, skips);
        cout << "Cipher text = " << str1 << endl;
        cout << "Decrypted text = " << decrypt(str1, skips) << endl;
    }
    else {
        cout << "Invalid skip value\n";
    }
    return 0;
}
