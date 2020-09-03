#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[100001];
bool vis[100001] = {false};

void dfsIterative(int src) {
    stack<int> S;
    S.push(src);
    vis[src] = true;
    while(!S.empty()) {
        int node = S.top();
        S.pop();

        cout << node << " ";

        for(int child:Nodes[node]) {
            if(vis[child] == false)
                S.push(child), vis[node] = true;
        }
    }
}

int main() {
    int V = 10;
    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {3,5},
        {3,4},

        {6,7},
        {10,9},
        {10,8}
    };

    int a, b;

    for(auto E:edges) {
        a = E[0], b = E[1];
        
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }
    // memset(vis, false, sizeof(vis));
    
    for(int i=1; i<=V; i++) {
        if(vis[i] == false){
            dfsIterative(i);
        cout << "\n";}
    }
}