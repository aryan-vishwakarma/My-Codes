#include<bits/stdc++.h>
using namespace std;

#define max_v 20
int V;

void printSolution(int color[]);

bool isSafe(bool graph[max_v][max_v], int color[])
{
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
bool graphColoring(bool graph[max_v][max_v], int m, int i,
    int color[max_v])
{
    if (i == V) {
        if (isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }
    for (int j = 1; j <= m; j++) {
        color[i] = j;

        if (graphColoring(graph, m, i + 1, color))
            return true;

        color[i] = 0;
    }

    return false;
}
void printSolution(int color[])
{
    cout << "Solution Exists:" " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i];
    cout << "\n";
}
int main()
{
    int m;
    cout << "Enter no. of vertices : ";
    cin >> V;
    bool graph[max_v][max_v];
    cout << "Enter the graph\n";
    for (int i = 0; i < V; i++) {
        cout << "Enter row no. " << (i + 1) << "\n";
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }
    cout << "Enter no. of colors : ";
    cin >> m;
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";

    return 0;
}