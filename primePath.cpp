#include<bits/stdc++.h>
using namespace std;
vector<int> Nodes[100001];
int vis[100001];
int dist[100001];
vector<int> primes;

bool isPrime(int n) {
    for(int i=2; i*i <= n; i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

bool isValid(int a, int b) {
    int count = 0;

    while(a>0) {
        if(a%10 != b%10) count++;
        a/=10;
        b/=10;
    }

    return count == 1;
}

void buildGraph() {
    for(int i=1000; i<=9999; i++) {
        if(isPrime(i))
            primes.push_back(i);
    }

    for(int i=0; i<primes.size()-1; i++) {
        for(int j=i+1; j<primes.size(); j++) {
            int a = primes[i];
            int b = primes[j];

            if(isValid(a, b)) {
                Nodes[a].push_back(b);
                Nodes[b].push_back(a);
            }
        }
    }
}

void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    dist[node] = 0;
    vis[node] =1;

    while(!Q.empty()) {
        int curr = Q.front(); Q.pop();
        for(int child:Nodes[curr]) {
            if(vis[child] == 0) {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                Q.push(child);
            }
        }
    }
}

int main() {
    int t; cin >> t;

    buildGraph();

    while(t--) {
        for(int i=1000; i<=9999; i++) {
           dist[i] = -1, vis[i] = 0;
        }

        int a, b;
        cin >> a >> b;

        bfs(a);

        if(dist[b] == -1)
            cout << "Impossible\n";
        else 
            cout << dist[b];
    }
}