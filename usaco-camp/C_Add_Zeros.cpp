#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 300001;
bool vis[MAXN];
ll a[MAXN];
map<ll, vector<int>> adj;
ll ans;

void dfs(ll u, ll currsz) {
    if (vis[u]) return;
    vis[u] = true;
    ans = max(ans, currsz+u-1);
    for (auto x : adj[currsz+u-1]) {
        dfs(x, currsz+u-1);
    }
}

int n;
void solve() {
    cin >> n;
    adj.clear(); ans = n;

    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        cin >> a[i];
        //a_i = |a|+1-i
        //->|a| = a_i-1-i
        adj[a[i]+i-1].emplace_back(i);
    }
    for (auto x : adj[n]) {
        dfs(x, n);
    }
    cout << ans << "\n";
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
