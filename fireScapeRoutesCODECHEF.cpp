#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[100001];
int vis[100001];
int cc_count;

void dfs(int node) {
    vis[node] = 1;
    cc_count++;
    for(int child:Nodes[node]) {
        if(vis[child] == 0) {
            dfs(child);
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >>  n >> m;
        int a,b;
        for(int i=1; i<=n; i++) Nodes[i].clear(), vis[i] = 0;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }

        int count = 0;
        int res = 1;
        for(int i=1; i<=n; i++) {
            if(vis[i] == 0) {
                cc_count = 0;
                dfs(i);
                count++;
                res *= cc_count;
            }
        }

        cout << count << " " << res << "\n";

    }
}