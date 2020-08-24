// Is this graph a tree
//1. Check for connected graph counts to one, 
//2. Number of edges(m) == One less than number of Nodes(n) [m == n-1]

#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[10001];
int vis[10001];

void dfs(int src) {
    vis[src] = 1;
    for(int child:Nodes[src]) {
        if(vis[child] == 0)
            dfs(child);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    int x = m;
    while(m--) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }
    int count = 0;
    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            dfs(i); 
            count++;
        }
    }

    if(count == 1 && x == n-1)
        cout << "YES";
    else
        cout << "NO";

}