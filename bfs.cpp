#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[10001];
int dist[10001];
int vis[10001];

void bfs(int src) {
    queue<int> Q;

    Q.push(1);
    vis[1] = 1;
    dist[src] = 0;
    while(!Q.empty()) {
        int curr = Q.front(); Q.pop();
        for(int child:Nodes[curr]) {
            if(vis[child] == 0) {
                vis[child] = 1;
                dist[child] = dist[curr] +1 ;
                Q.push(child);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a, b;
        for(int i=1; i<=n; i++) Nodes[i].clear(), vis[i] = 0, dist[i] = 0;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }
        bfs(1);
        cout << dist[n] << "\n";
    }
}