#define _GLIBCXX_DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <bitset>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200000;

int n, k;
vector<int> adj[MAXN];
int mld[MAXN], bessieDist[MAXN]; // minimum leaf distance
int dp[MAXN];
queue<pii> q;

// the dfs that computes the minimum leaf distance
int dfs_MLD(int v, int p) {
    if (adj[v].size() == 1) {
        mld[v] = 0;
    }
    else {
        for (auto x : adj[v]) {
            if (x != p) {
                mld[v] = min(mld[v], dfs_MLD(x, v)+1);
            }
        }
    }
    //cerr << "mininum leaf distance of vertex " << v << " : " << mld[v] << "\n";
    return mld[v]; 
}

// there exists a leaf that can reach vertex v before
int dfs_COVERAGE(int v, int p) {
    if (bessieDist[v] < mld[v]) {
        for (auto x : adj[v]) {
            if (x != p) {
                dp[v] += dfs_COVERAGE(x, v);
            }
        }
    }
    else {
        dp[v] = 1;
    }
    //cerr << dp[v] << " many FJs does it take to cover " << v << " and its children" << "\n";
    return dp[v];
}

void solve() {
    cin >> n >> k; k--;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        mld[i] = INT32_MAX;
    }
    mld[n-1] = INT32_MAX;

    mld[k] = dfs_MLD(k, -1);
    q.push(mp(k, -1));
    dbg(k);
    bessieDist[k] = 0;
    while(!q.empty()) {
        auto c = q.front(); q.pop();
        for (auto x : adj[c.first]) {
            if (x != c.second) {
                bessieDist[x] = bessieDist[c.first]+1;
                q.push(mp(x, c.first));
            }
        }
    }

    cout << dfs_COVERAGE(k, -1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
