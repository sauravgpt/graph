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
    int n; cin >> n;
    int m; cin >> m;
    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    cout << dfs(1, 0);
}