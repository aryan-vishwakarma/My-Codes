#include <iostream>
using namespace std;

int main()
{
    int n, i, winner_pos, next_winner_pos, looser_pos, next_looser_pos;
    cout << "Enter the number of players: ";
    cin >> n;
    int a[n];

    cout << "Enter scores of " << n << " players\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    winner_pos = 0;
    looser_pos = 0;
    next_winner_pos = 0;
    next_looser_pos = 0;

    for (i = 1; i < n; i++)
    {
        if (a[i] > a[winner_pos])
        {
            next_winner_pos = winner_pos;
            winner_pos = i;
        }
        else if (a[i] > a[next_winner_pos])
        {
            next_winner_pos = i;
        }
        else if (a[i] < a[looser_pos])
        {
            next_looser_pos = looser_pos;
            looser_pos = i;
        }
        else if (a[i] < a[next_looser_pos])
        {
            next_looser_pos = i;
        }
    }

    cout << "Winner is Player " << (winner_pos + 1) << endl;
    cout << "Next Winner is Player " << (next_winner_pos + 1) << endl;
    cout << "Looser is Player " << (looser_pos + 1) << endl;
    cout << "Next Looser is Player " << (next_looser_pos + 1) << endl;

    return 0;
}