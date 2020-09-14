#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[10001];
int vis[10001];
int farthestNode;
int cc_count;

void dfs(int node) {
    farthestNode = node;
    vis[node] = 1;
    cc_count += 1;
    for(int child: Nodes[node]) {
        if(vis[child] == 0) {
            dfs(child);
        }
    }
}

int main() {
    int node; cin >> node;
    int edges; cin >> edges;
        int a, b;
    for(int i=0; i<edges; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }
    
    for(int i=1; i<=node; i++)
        vis[i] = 0;
    
    dfs(1);
    cc_count = 0;
    dfs(farthestNode);
    
    cout << cc_count;
}