#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, y1, y2, y3;
    cout << "Enter x and y coordinates of P1\n";
    cin >> x1 >> y1;
    cout << "Enter x and y coordinates of P2\n";
    cin >> x2 >> y2;
    cout << "Enter x and y coordinates of P3\n";
    cin >> x3 >> y3;
    int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (a == 0)
        cout << "P3 lies on the line P1P2\n";
    else
        cout << "P3 does not lie on the line P1P2\n";
}