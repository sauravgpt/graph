#include<bits/stdc++.h>
using namespace std;
vector<int>  Nodes[10001];
int vis[1001];
int subTree[1001];

int dfs(int node) {
    vis[node] = 1;
    int currSize = 1;

    for(int child:Nodes[node]) {
        if(vis[child] == 0) {
            currSize += dfs(child);
        }
    }

    subTree[node] = currSize;
    return currSize;
}

