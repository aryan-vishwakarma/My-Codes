#include<iostream>
using namespace std;

string XOR(string a, string b) {
    if (a.length() != b.length())return NULL;
    string c = "";
    char ch;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) {
            ch = '0';
        }
        else {
            ch = '1';
        }
        c.push_back(ch);
    }
    return c;
}

bool isAllZero(string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != '0') {
            return false;
        }
    }
    return true;
}

string crc(string data, string divisor) {
    int data_l = data.length();
    int divisor_l = divisor.length();
    string temp = data;
    string sub;
    string rem;
    string zeroes = "";
    for (int i = 0; i < divisor_l; i++) {
        zeroes += '0';
    }
    for (int i = 0; i < divisor_l - 1; i++) {
        temp.push_back('0');
    }
    sub = temp.substr(0, divisor_l);
    for (int i = 0; i < data_l; i++) {
        if (sub[0] == '0') {
            rem = XOR(sub, zeroes).substr(1);
        }
        else {
            rem = XOR(sub, divisor).substr(1);
        }
        if (i != data_l - 1) {
            sub = rem + temp[i + divisor_l];
        }
    }
    return(data + rem);
}

void crcCheck(string data, string divisor) {
    int data_l = data.length();
    int divisor_l = divisor.length();
    string zeroes = "";
    for (int i = 0; i < divisor_l; i++) {
        zeroes += '0';
    }
    string sub, rem;
    sub = data.substr(0, divisor_l);
    for (int i = 0; i < data_l - divisor_l + 1; i++) {
        if (sub[0] == '0') {
            rem = XOR(sub, zeroes).substr(1);
        }
        else {
            rem = XOR(sub, divisor).substr(1);
        }
        if (i != data_l - divisor_l) {
            sub = rem + data[i + divisor_l];
        }
    }
    if (isAllZero(rem)) {
        cout << "Error is not present\n";
        cout << "Data is " << data.substr(0, data_l - divisor_l + 1);
    }
    else {
        cout << "Error is present\n";
    }
}
int main() {
    string data, divisor;
    cout << "Enter data : ";
    cin >> data;
    cout << "Enter divisor : ";
    cin >> divisor;
    cout << crc(data, divisor);
    cout << "\nEnter data to check error : ";
    cin >> data;
    cout << "Enter divisor : ";
    cin >> divisor;
    crcCheck(data, divisor);
}
