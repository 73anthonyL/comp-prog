#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <math.h>
#include <numeric>
#include <set>
#include <cstdint>
#include <string>
#include <map>
#include <bitset>
using namespace std;
using ll = long long;
#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

const int MAXN = 5001;
array<ll, MAXN> val, sts;
array<vector<int>, MAXN> adj;

ll balTree(int u) {
    sts[u] += val[u];
    for (auto x : adj[u]) {
        sts[u] += balTree(x);
    }

    return sts[u];
}

int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].emplace_back(i);
    }


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

// tree dp problem
