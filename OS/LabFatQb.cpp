#include <bits/stdc++.h>
using namespace std;

void printFragmentation(int allocation[], int n, int items[], int part[]) {
    int rem[n];
    for (int i = 0; i < n; i++) {
        rem[i] = part[i];
    }
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            rem[allocation[i]] -= items[i];
        }
    }
    cout << "Internal fragmentation\n";
    for (int i = 0; i < n; i++) {
        if (rem[i] != 0) {
            cout << "Block " << (i + 1) <<" : "<< rem[i] << endl;
        }
    }
}

void firstFit(int partitions[], int n_partitions, int items[], int n_items) {
    int allocation[n_items];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n_items; i++) {
        for (int j = 0; j < n_partitions; j++) {
            if (partitions[j] >= items[i]) {
                allocation[i] = j;
                partitions[j] -= items[i];
                break;
            }
        }
    }
    printFragmentation(allocation, n_items, items, partitions);
}

void worstFit(int partitions[], int n_partitions, int items[], int n_items) {
    int allocation[n_items];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n_items; i++) {
        int k = -1;
        for (int j = 0; j < n_partitions; j++) {
            if (partitions[j] >= items[i]) {
                if (k == -1)
                    k = j;
                else if (partitions[k] < partitions[j])
                    k = j;
            }
        }
        if (k != -1) {
            allocation[i] = k;
            partitions[k] -= items[i];
        }
    }
    printFragmentation(allocation, n_items, items, partitions);
}

int main() {
    int n_partitions, n_items;
    cout << "Enter no. of partitions : ";
    cin >> n_partitions;
    int partitions[n_partitions];
    cout << "Enter size of all partitions\n";
    for (int i = 0; i < n_partitions; i++) {
        cin >> partitions[i];
    }
    cout << "Enter no. of items to be allocated : ";
    cin >> n_items;
    int items[n_items];
    for (int i = 0; i < n_items; i++) {
        cout << "Enter size of item " << (i + 1) << " : ";
        cin >> items[i];
    }
    cout << "\nWORSTFIT\n";
    worstFit(partitions, n_partitions, items, n_items);
    cout << "\nFIRSTFIT\n";
    firstFit(partitions, n_partitions, items, n_items);
}