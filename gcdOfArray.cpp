#include<bits/stdc++.h>
using namespace std;

int solve(priority_queue<int> &Q, int n) {
    while(Q.size() > 1) {
        int x = Q.top(); Q.pop();
        int y = Q.top(); Q.pop();
        
        Q.push(__gcd(x, y));
    }
    
    int res = Q.top(); Q.pop();
    return res;
}

int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
	
	
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    priority_queue<int> Q;
	    int x;
	    for(int i=0; i<n; i++){
	        cin >> x;
	        Q.push(x);
	    }
	    
	    cout << solve(Q, n) << "\n";
	   //cout << 1 << "\n";
	}
}