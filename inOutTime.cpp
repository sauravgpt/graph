#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[1001];
int vis[1001];
int inTime[1001];
int outTime[1001];
int timer = 1;


void calculateTime(int node) {
    vis[node] = 1;
    inTime[node] = timer++;

    for(int child:Nodes[node]) {
        if(vis[child] == 0) 
            calculateTime(child);
    }

    outTime[node] = timer++;
}

int main() {
    
}