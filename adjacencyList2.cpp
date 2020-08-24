#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; //Number of Nodes
    int m; //NUmber of edges

    vector<int> Nodes[n + 1];
    int a, b;

    while (m--)
    {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }
}

