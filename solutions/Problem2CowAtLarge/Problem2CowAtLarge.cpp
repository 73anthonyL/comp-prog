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

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200000;

int n, k;
vector<int> adj[MAXN];
int mld[MAXN], bessieDist[MAXN]; // minimum leaf distance
int dp[MAXN];
queue<int> q;

// the dfs that computes the minimum leaf distance
int dfs_MLD(int v, int p) {
    cout << "mld call" << "\n";
    for (auto x : adj[v]) {
        if (x != p) {
            mld[v] = min(mld[v], dfs_MLD(x, v)+1);
        }
    }
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
    return dp[v];
}

void solve() {
    cin >> n >> k; k--;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    mld[k] = dfs_MLD(k, -1);
    q.push(k);
    bessieDist[k] = 0;
    while(!q.empty()) {
        int c = q.front(); q.pop();
        dbg(c);
        for (auto x : adj[c]) {
            if (x != c) {
                bessieDist[x] = bessieDist[c]+1;
                q.push(x);
            }
        }
    }

    cout << dfs_COVERAGE(k, -1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
