#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
void solve() {
    cin >> n;
    // find the center of the graph using 2 BFSs
    // root the tree at the center
    // use dp to find XOR of path from each node to the tree center
    // for each query, 
    // update will update nodes up to the top in the dp array
    // other query will just be dp[a] ^ dp[b] ^ A[lca]
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
