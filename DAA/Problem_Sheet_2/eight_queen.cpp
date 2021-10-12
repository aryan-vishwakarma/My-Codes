#include <stdbool.h>
#include <iostream>
using namespace std;

#define max_n 50
int N;
void printSolution(int board[max_n][max_n]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int board[max_n][max_n], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[max_n][max_n], int row) {
    if (row >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;

            if (solveNQUtil(board, row + 1))
                return true;

            board[row][i] = 0;
        }
    }

    return false;
}

void initialise(int board[max_n][max_n]) {
    for (int i = 0; i < max_n; i++)
        for (int j = 0; j < max_n; j++)
            board[i][j] = 0;
}

void solveNQueen() {
    int board[max_n][max_n];

    cout << "Enter N for N*N board: ";
    cin >> N;

    initialise(board);

    if (solveNQUtil(board, 0) == false)
        printf("Solution does not exist");
    else
        printSolution(board);
}

int main() {
    solveNQueen();
    return 0;
}
