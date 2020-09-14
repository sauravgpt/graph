#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[100001];
vector<int> topo;
int IN[100001];


vector<int> kahnAlgo(int numberOfNodes) {
    queue<int> Q;
    for(int i=1; i<=numberOfNodes; i++) {
        if(IN[i] == 0)
            Q.push(i);
    }

    while(!Q.empty()) {
        int node = Q.front(); Q.pop();
        topo.push_back(node);

        for(int child:Nodes[node]) {
            IN[child]--;
            if(IN[child] == 0)
                Q.push(child);
        }
    }
}

int main() {
    int n, m, a, b;

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        IN[b]++;
    }

    kahnAlgo(n);

    for(int i:topo)
        cout << i << " ";
}