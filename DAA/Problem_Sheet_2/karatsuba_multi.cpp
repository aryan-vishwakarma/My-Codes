#include <string>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int makeEqualLength(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}
string multiply(string x, string y) {
    int n = makeEqualLength(x, y);
    if (n == 0) return 0;
    if (n == 1) return to_string(stoi(y) * stoi(x));
    
    int fh = n / 2;
    int sh = (n - fh);

    string x1, y1, x2, y2, a, b, c, prod;
    x1 = x.substr(0, fh);
    x2 = x.substr(fh, sh);
    y1 = y.substr(0, fh);
    y2 = y.substr(fh, sh);

    // if (x1.length() == 0)
    //     x1 = "0";
    // if (x2.length() == 0)
    //     x2 = "0";
    // if (y1.length() == 0)
    //     y1 = "0";
    // if (y2.length() == 0)
    //     y2 = "0";

    a = multiply(x1, y1);
    c = multiply(x2, y2);

    // cout << "x1: " << x1 << "\nx2: " << x2 << "\ny1: " << y1 << "\ny2: " << y2 << endl;
    // cout << "a=" << a << "\nc=" << c << endl;

    // cout << stoi(
    //     multiply(to_string(stoi(x1) + stoi(x2)), to_string(stoi(y1) + stoi(y2)))
    // ) << endl;
    b = to_string(stoi(
        multiply(to_string(stoi(x1) + stoi(x2)), to_string(stoi(y1) + stoi(y2)))
    ) - stoi(a) - stoi(c));
    // cout << "b=" << b << endl;
    prod = to_string(stoi(multiply(a, to_string((int)pow(10, 2 * n)))) +
        stoi(multiply(b, to_string((int)pow(10, n)))) + stoi(c));

    return(prod);
}
int main() {
    string x, y;
    cout << "Enter first number : ";
    cin >> x;
    cout << "Enter second number : ";
    cin >> y;
    cout << x << "*" << y << " is : " << multiply(x, y) << endl;
}