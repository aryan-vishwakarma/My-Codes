
#include <bits/stdc++.h>
using namespace std;

#define maxV 20

int graph[maxV][maxV];
int arr[maxV], V;
bool is_clique(int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++)
            if (graph[arr[i]-1][arr[j]-1] == 0)
                return false;
    }
    return true;
}
int main() {
    int k;
    cout << "Enter no. of vertices : ";
    cin >> V;
    cout << "Enter graph\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "\nFOR the proposed solution\n" <<
        "Enter size of subset : ";
    cin >> k;
    cout << "Enter the elements of the subset\n";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    if (is_clique(k)) {
        cout << "Yes, the proposed solution forms a clique\n";
    }
    else {
        cout << "No, the proposed solution doesn't forms a clique\n";
    }
}