#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[10001];
int vis[10001];
int col[10001];

bool dfs(int src, int color) {
    vis[src] = 1;
    col[src] = color;

    for(int child:Nodes[src]) {
        if(vis[child] == 0) {
            if(dfs(child, color^1) == false)
                return false;
        } else if(col[src] == col[child])
            return false;
    }

    return true;
}

int main(){
    int t; cin >> t;
    int test = 1;
    while(t--) {
        int n; cin >> n;
        int m; cin >> m;

        for(int i=1; i<=n; i++) {
            Nodes[i].clear();
            vis[i] = 0;
        }

        int a, b;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }

        bool ans = true;

        for(int i=1; i<=n; i++) {
            if(vis[i] == 0) {
                ans = dfs(i, 0);
                if(!ans)  break;
            }
        }


        cout << "Scenario #" << test << ":\n";
        if(!ans) cout << "Suspicious bugs found!\n";
        else cout << "No suspicious bugs found!\n";
        test++;
    }
}