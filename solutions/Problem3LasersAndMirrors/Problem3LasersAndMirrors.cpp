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
#define _GLIBCXX_DEBUG
#define mp make_pair

int n, xl, yl, xb, yb;
map<pii, int> m;
map<int, vector<int>> xLevel, yLevel;
void solve() {
    cin >> n;
    vector<vector<int>> adj(n+3, vector<int>());
    int ct = 1;
    for (int i = 0; i < n+2; i++) {
        int x, y; cin >> x >> y;
        m[mp(x, y)] = ct++;
        if (xLevel.find(x) == xLevel.end()) {
            xLevel[x] = {ct-1};
        }
        else {
            xLevel[x].emplace_back(ct-1);
        }

        if (yLevel.find(y) == yLevel.end()) {
            yLevel[y] = {ct-1};
        }
        else {
            yLevel[y].emplace_back(ct-1);
        }
    }

    for (auto [k, v] : xLevel) {
        if (v.size() == 1) continue;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                adj[v[i]].emplace_back(v[j]);
                adj[v[j]].emplace_back(v[i]);
            }
        }
    }

    for (auto [k, v] : yLevel) {
        if (v.size() == 1) continue;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                adj[v[i]].emplace_back(v[j]);
                adj[v[j]].emplace_back(v[i]);
            }
        }
    }
    
    vector<bool> vis(n+3);
    vector<int> dist(n+3, INT32_MAX);
    queue<int> q; q.push(1); dist[1] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        vis[v] = true;
        for (auto x : adj[v]) {
            if (!vis[x]) {
                dist[x] = dist[v]+1; 
                q.push(x);
            }
        }
    }

    if (dist[2] == INT32_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << dist[2]-1 << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    
	int t = 1;
	while (t--) {
		solve();
	}
}
