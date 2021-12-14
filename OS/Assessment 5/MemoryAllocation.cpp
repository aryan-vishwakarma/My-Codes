#include <bits/stdc++.h>
using namespace std;
void firstFit(int par[], int n_par, int it[], int ni);
void bestFit(int par[], int n_par, int it[], int ni);
void worstFit(int par[], int n_par, int it[], int ni);
void printAllocation(int allocation[], int n);
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
    int ch;
    cout << "Enter\n1 for FIRSTFIT"
        << "\n2 for BESTFIT"
        << "\n3 for WORSTFIT"
        << endl;
    cin >> ch;
    switch (ch) {
    case 1:
        firstFit(partitions, n_partitions, items, n_items);
        break;
    case 2:
        bestFit(partitions, n_partitions, items, n_items);
        break;
    case 3:
        worstFit(partitions, n_partitions, items, n_items);
    default:
        cout << "Invalid Choice...\n";
    }
    return 0;
}
void printAllocation(int allocation[], int n, int items[]) {
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++){
        cout << " " << i + 1 << "\t\t" << items[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
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
    printAllocation(allocation, n_items, items);
}
void bestFit(int partitions[], int n_partitions, int items[], int n_items) {
    int allocation[n_items];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n_items; i++) {
        int k = -1;
        for (int j = 0; j < n_partitions; j++) {
            if (partitions[j] >= items[i]) {
                if (k == -1)
                    k = j;
                else if (partitions[k] > partitions[j])
                    k = j;
            }
        }
        if (k != -1) {
            allocation[i] = k;
            partitions[k] -= items[i];
        }
    }
    printAllocation(allocation, n_items, items);
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
    printAllocation(allocation, n_items, items);
}
// int main()
// {
//     int blockSize[] = { 100, 500, 200, 300, 600 };
//     int processSize[] = { 212, 417, 112, 426 };
//     int m = sizeof(blockSize) / sizeof(blockSize[0]);
//     int n = sizeof(processSize) / sizeof(processSize[0]);
//     worstFit(blockSize, m, processSize, n);
//     return 0;
// }
