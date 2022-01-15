#include <bits/stdc++.h>
using namespace std;

#define maxRowCol 30

void inputMatrix(float matrix[maxRowCol][maxRowCol], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(float matrix[maxRowCol][maxRowCol], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void transposeOfMatrix(float matrix[maxRowCol][maxRowCol], int m, int n, float transpose[maxRowCol][maxRowCol]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

float determinantOfMatrix(float matrix[maxRowCol][maxRowCol], int n) {
    if (n == 1)
        return (matrix[0][0]);
    float a1[maxRowCol][maxRowCol], d = 0.0;
    int i2, j2;
    for (int i = 0; i < n; i++){
        i2 = 0;
        j2 = 0;
        for (int i1 = 1; i1 < n; i1++){
            for (int j1 = 0; j1 < n; j1++){
                if (j1 == i)
                    continue;
                a1[i2][j2] = matrix[i1][j1];
                if (j2 == n - 2){
                    j2 = 0;
                    i2++;
                }
                else
                    j2++;
            }
        }
        if (i % 2 == 0)
            d += matrix[0][i] * determinantOfMatrix(a1, n - 1);
        else
            d -= matrix[0][i] * determinantOfMatrix(a1, n - 1);
    }
    return (d);
}

float cofactor(float matrix[maxRowCol][maxRowCol], int m, int row, int col) {
    float minor[maxRowCol][maxRowCol];
    int r, c;
    c = -1;
    r = 0;
    for (int i = 0; i < m; i++) {
        if (i == row) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (j == col) {
                continue;
            }
            if (c == m - 2) {
                minor[++r][0] = matrix[i][j];
                c = 0;
            }
            else {
                minor[r][++c] = matrix[i][j];
            }
        }
    }
    return(pow(-1, row + col) * determinantOfMatrix(minor, m - 1));
}

void cofactorMatrix(float matrix[maxRowCol][maxRowCol], int m, float cof_matrix[maxRowCol][maxRowCol]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cof_matrix[i][j] = cofactor(matrix, m, i, j);
        }
    }
}

int main() {
    int m, n;
    float matrix[maxRowCol][maxRowCol];
    float transpose[maxRowCol][maxRowCol];
    float cofactor_matrix[maxRowCol][maxRowCol];
    float adjoint[maxRowCol][maxRowCol];
    float determinant;
    cout << "Enter no. of rows of matrix : ";
    cin >> m;
    cout << "Enter no. of columns of matrix : ";
    cin >> n;
    cout << "\nEnter the matrix\n";
    inputMatrix(matrix, m, n);
    cout << "\nThe matrix is\n";
    displayMatrix(matrix, m, n);
    cout << "\nTranspose of the matrix is\n";
    transposeOfMatrix(matrix, m, n, transpose);
    displayMatrix(transpose, n, m);
    if (m == n && m > 1) {
        cout << "\nThe cofactor matrix is\n";
        cofactorMatrix(matrix, m, cofactor_matrix);
        displayMatrix(cofactor_matrix, m, m);
        cout << "\nAdjoint of matrix is\n";
        transposeOfMatrix(cofactor_matrix, m, m, adjoint);
        displayMatrix(adjoint, m, m);
        determinant = determinantOfMatrix(matrix, m);
        if (determinant) {
            float inverse[maxRowCol][maxRowCol];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    inverse[i][j] = adjoint[i][j] / determinant;
                }
            }
            cout << "\nInverse of matrix is\n";
            displayMatrix(inverse, m, m);
        }
        else {
            cout << "\nInverse does not exist since deterrminant is zero\n";
        }
    }

    int a, b;
    cout << "\nEnter a for (a mod b) calculation : ";
    cin >> a;
    cout << "Enter b for (a mod b) calculation : ";
    cin >> b;
    cout << "\n" << a << " mod " << b << " is : " << (a % b);
    return 0;
}