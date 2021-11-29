#include <limits>
#include <bits/stdc++.h>
using namespace std;
#define maxV 20
#define INF 99999

int V;

void printSolution(int dist[][maxV]);
void floydWarshall(int graph[][maxV]){
    int dist[V][maxV], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][maxV]){
    cout << "The following matrix shows the shortest "
        "distances"
        " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}

int main() {

    cout << "Enter no. of vertices : ";
    cin >> V;
    int graph[V][maxV];

    cout << "Enter graph\nFor INF enter 99999\n";
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph);
    return 0;
}
