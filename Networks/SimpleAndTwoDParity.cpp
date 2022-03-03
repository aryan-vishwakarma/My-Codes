#include<iostream>
using namespace std;

void inverseBit(char &ch) {
    if (ch == '1') {
        ch = '0';
    }
    else {
        ch = '1';
    }
}

string oneByteParity(string str) {
    int l = str.length();
    char parity = '0';
    for (int i = 0; i < l; i++) {
        if (str[i] == '1') {
            inverseBit(parity);
        }
    }
    str += parity;
    return str;
}

string simpleParity(string str) {
    int l = str.length();
    if (l % 8 != 0)return NULL;
    string str1 = "";
    string sub;
    for (int i = 0; i < l; i += 8) {
        sub = str.substr(i, 8);
        str1 += oneByteParity(sub);
    }
    return str1;
}

string twoDParity(string str) {
    str = simpleParity(str);
    int l = str.length();
    char parity;
    for (int i = 0; i < 9; i++) {
        parity = '0';
        for (int j = i; j < l; j += 9) {
            if (str[j] == '1') {
                inverseBit(parity);
            }
        }
        str += parity;
    }
    return str;
}

void simpleParityCheck(string str) {
    int l = str.length();
    if (l % 9 != 0)return;
    string sub;
    int flag = 0;
    for (int i = 0; i < l; i += 9) {
        sub = str.substr(i, 8);
        if (str[i + 8] != oneByteParity(sub)[8]) {
            flag = 1;
        }
    }
    if (flag == 1) {
        cout << "Error is present\n";
    }
    else {
        cout << "Error is not present\n";
    }
}

void twoDParityCheck(string str) {
    int l = str.length();
    if (l % 9 != 0)return;
    string sub;
    int flag = 0;
    for (int i = 0; i < l; i += 9) {
        sub = str.substr(i, 8);
        if (str[i + 8] != oneByteParity(sub)[8]) {
            flag = 1;
        }
    }
    if (flag == 0) {
        char parity;
        for (int i = 0; i < 9; i++) {
            parity = '0';
            for (int j = i; j < l; j += 9) {
                if (str[j] == '1') {
                    inverseBit(parity);
                }
            }
            if (parity != '0') {
                cout << "Error is present\n";
                return;
            }
        }
        cout << "Error is not present\n";
        return;
    }
    cout << "Error is present\n";
}

void printData(string str, int n) {
    for (int i = 0; i < str.length(); i+=n) {
        cout << str.substr(i, n) << " ";
    }
    cout << endl;
}
int main() {
    int ch;
    cout << "Enter 1 for Simple Parity 2 for two D parity\n";
    cin >> ch;
    string data, data2;
    switch (ch) {
    case 1:
        cout << "Enter data : ";
        cin >> data;
        printData(simpleParity(data), 9);
        cout << "Enter data to check error : ";
        cin >> data2;
        simpleParityCheck(data2);
        break;
    case 2:
        cout << "Enter data : ";
        cin >> data;
        printData(twoDParity(data), 9);
        cout << "Enter data to check error : ";
        cin >> data2;
        twoDParityCheck(data2);
        break;
    default:
        cout << "INVALID CHOICE\n";
    }
    // printData(simpleParity("1101111010011011"), 9);
    // printData(twoDParity("1101111010011011"), 9);
    // simpleParityCheck("110111100100110110");
    // twoDParityCheck("110111100100110111010001011");
}