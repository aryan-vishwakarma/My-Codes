#include <bits/stdc++.h>
using namespace std;

#define maxV 20

int graph[maxV][maxV];
int V;
int subset[maxV];
int sub_n;

void inputGraph() {
    cout << "Enter no. of vertices : ";
    cin >> V;
    cout << "Enter graph\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
}

void inputSubset() {
    cout << "Enter no. of vertices in candidate solution : ";
    cin >> sub_n;
    cout << "Enter the elements of subset\n";
    for (int i = 0; i < sub_n; i++) {
        cin >> subset[i];
    }
}

bool notInSubset(int k) {
    for (int i = 0; i < sub_n; i++) {
        if (k == subset[i]) {
            return false;
        }
    }
    return true;
}

bool check() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0 && i!=j) {
                if (notInSubset(i) && notInSubset(j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    inputGraph();
    inputSubset();
    if (check()) {
        cout << "Yes, the candidate vertices are vertex cover\n";
    }
    else {
        cout << "No, the candidate vertices are not vertex cover\n";
    }
}