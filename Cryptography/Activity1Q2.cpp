#include<iostream>
using namespace std;

string decrypt(string str, int skips) {
    int len = str.length();
    string str1 = "";
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str1.push_back((char)('A' + (str.at(i) - skips - 'A' + 26) % 26));
        }
        else {
            str1.push_back(str[i]);
        }
    }
    return str1;
}
int main() {
    int freq[26];
    string str;
    cout << "Enter the string : ";
    cin >> str;
    int l = str.length();

    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < l; i++) {
        if (isalpha(str[i])) {
            freq[str[i] - 'A']++;
        }
    }
    int max = freq[0];
    int max_index = 0;
    for (int i = 0; i < 26; i++) {
        if (max < freq[i]) {
            max = freq[i];
            max_index = i;
        }
    }
    int skips = (max_index - 4 + 26) % 26;//since 'E' is 4
    cout << decrypt(str, skips);
}