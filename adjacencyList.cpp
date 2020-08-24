#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> ADJ[], int u, int v)
{
    ADJ[u].push_back(v);
    ADJ[v].push_back(u);
}

void printGraph(vector<int> ADJ[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (auto j : ADJ[i])
            cout << j << " ";
        cout << "\n";
    }
}

int main()
{
    int V = 4;
    vector<int> ADJ[V];
    addEdge(ADJ, 1, 2);
    addEdge(ADJ, 0, 3);
    addEdge(ADJ, 3, 2);
    addEdge(ADJ, 1, 3);
    addEdge(ADJ, 2, 3);

    printGraph(ADJ, V);

    return 0;
}