//LOngest Path in  a Tree
#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[10001];
int vis[10001];
int maxD, maxNode;

void dfs(int node, int dis) {
    vis[node] = 1;
    if(maxD < dis) maxD = dis, maxNode = node;

    for(int child:Nodes[node]) {
        if(vis[child] == 0) {
            dfs(child, dis+1);
        }
    }
}

int main() {
    int n; cin >> n;
    int a, b;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    maxD = -1;
    dfs(1, 0);

    for(int i=1; i<=n; i++) vis[i] = 0;

    dfs(maxNode, 0);
    cout << maxD;
}