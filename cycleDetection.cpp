#include<bits/stdc++.h>
using namespace std;
vector<int>  Nodes[10001];
int vis[1001];

bool detectCycle(int src, int par) {
    vis[src] = 1;

    for(int child:Nodes[src]) {
        if(vis[child] == 0) {
            if(detectCycle(child, src) == true)
                return true;
        } else if(child != par)
            return true;
    }

    return false;
}


int main() {
    
}