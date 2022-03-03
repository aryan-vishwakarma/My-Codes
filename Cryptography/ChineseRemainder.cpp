#include<iostream>
using namespace std;

#define MAX 100

int modularInverse(int a, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((a * i) % mod == 1) {
            return i;
        }
    }
}

int main() {
    int a[MAX], n[MAX], Nj[MAX], N, c[MAX], size, x;
    cout << "Enter no. of equations : ";
    cin >> size;

    cout << "Enter array of a\n";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << "Enter array of n\n";
    for (int i = 0; i < size; i++) {
        cin >> n[i];
    }

    //Calculating N, N = product(ni)
    N = 1;
    for (int i = 0; i < size; i++) {
        N *= n[i];
    }

    //Calculating Nj, Nj = N / nj;
    for (int i = 0; i < size; i++) {
        Nj[i] = N / n[i];
    }

    //Calculating c[i], Nj[i] * c[i] === 1 (mod n[i])
    for (int i = 0; i < size; i++) {
        c[i] = modularInverse(Nj[i], n[i]);
    }

    //Calculating x, x = sum(a[i] * Nj[i] * c[i]) mod N
    x = 0;
    for (int i = 0; i < size; i++) {
        x += a[i] * Nj[i] * c[i];
    }
    x = x % N;
    cout << "X = " << x << endl;
}