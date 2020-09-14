#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int vis[1001];
int low[1001];
int in[1001];
int timer = 1;

void dfs(int node, int par) {
    in[node] = timer;
    low[node] = timer++;
    vis[node] = 1;

    for(int child:adj[node]) {
        if(child == par) continue;

        if(vis[child] == 1) {
            low[node] = min(low[node], low[child]);
        } else {
            dfs(child, node);

            if(low[child] > low[node]) {
                cout << node << " - " << child << endl;
            }

            low[node] = min(low[node], low[child]);
        }
    }
}

int main() {
    int V = 13;
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 5}, {1, 6}, {1, 7},

        {2, 1}, {2, 3}, {2, 4}, 

        {3, 2}, {4, 2},

        {5, 1}, {5, 8}, {5, 9}, {5, 10}, {5, 12},

        {6, 1}, {6, 7},

        {7, 1}, {7, 6},

        {8, 5}, {8, 9},

        {9, 5}, {9, 8},

        {10, 5}, {10, 11}, {10, 12},

        {11, 10},

        {12, 5}, {12, 10}, {12, 13},

        {13, 12}
    };
    int u, v;
    for(int i=0; i<edges.size(); i++) {
        u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
}