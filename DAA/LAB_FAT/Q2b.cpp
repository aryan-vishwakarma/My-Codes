#include<iostream>
#include <list>
using namespace std;
class Graph
{
    int V; 
    list<int>* adj; 
public:
    Graph(int V); 
    void addEdge(int v, int w); 
    void solve(); 
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}
void Graph::solve()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int>::iterator i;
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
        if (!visited[i])
            cout << i << " ";
}
int main()
{
    int v;
    cout << "Enter no. of vertices : ";
    cin >> v;
    cout << "Enter the graph\n";
    int gr[v][v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> gr[i][j];
        }
    }
    Graph g(v);
    for (int i = 1; i < v; i++) {
        for (int j = i; j < v; j++) {
            if (gr[i][j]) {
                g.addEdge(i, j);
            }
        }
    }
    g.solve();
    return 0;
}
