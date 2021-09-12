
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_denominations, amount, coins;
    cout << "Enter number of denominations : ";
    cin >> no_of_denominations;
    int denominations[no_of_denominations];
    cout << "Enter the denominations :\n";
    for (int i = 0; i < no_of_denominations; i++)
        cin >> denominations[i];
    cout << "Enter the amount M : ";
    cin >> amount;
    sort(denominations, denominations + no_of_denominations, greater<int>());
    int i = 0, f = 0;
    coins = 0;
    while (amount > 0)
    {
        coins += amount / denominations[i];
        amount = amount % denominations[i];
        if (amount < denominations[i])
            i++;
        if (i >= no_of_denominations)
        {
            f++;
            break;
        }
    }
    if (f == 0)
        cout << "\nTotal coins = " << coins << "\n\n";
    else
        cout << "\nNot possible with these denominations\n\n";
    return 0;
}