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
#define _GLIBCXX_DEBUG

bool works;
void dfs(int v, vector<set<int>> &adj, vector<bool> &vis, vector<bool> &pvis) {
    vis[v] = true;
    pvis[v] = true;
    for (auto x : adj[v]) {
        if (!vis[x]) {
            dfs(x, adj, vis, pvis);
        }
        else {
            if (pvis[x]) {
                works = false;
            }

        }
    }

    pvis[v] = false;
}

int n, k;
void solve() {
    cin >> n >> k;
    vector<set<int>> adj(n+1);
    vector<bool> vis(n+1), pvis(n+1);
    works = true;
    for (int i = 0; i < k; i++) {
        int last = -1;
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (j > 1) {
                adj[last].insert(a);
            }
            last = a;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dbg(i);
        for (auto x : adj[i]) {
            dbg(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, pvis);
        }
        if (!works) break;
    }

    cout << ((works) ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
        dbg(t);
		solve();
	}
}
