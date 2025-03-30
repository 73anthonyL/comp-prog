#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200001;

int n, q;
vector<int> adj[MAXN];
int dist[MAXN], depth[MAXN], ET[MAXN*2], FO[MAXN];
int ct = 0;

int dfs(int v, int p, int d) {
	ET[ct++] = v;
	for (auto x : adj[v]) {
		if (x != p) {
			dist[v] += dfs(x, v, d);
		}
	}
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
