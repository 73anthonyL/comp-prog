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

const int MAXP = 20000;

int n, p;
int ct = 0;
map<int, vector<int>> xLevel, yLevel;
map<pii, int> id;
array<vector<int>, MAXP> adj;
array<bool, MAXP> vis;
array<int, MAXP> dist, nodeNum;

void dfs(int v) {
    vis[v] = true;
    dist[v] = ct++;
    nodeNum[dist[v]] = v;
    for (auto x : adj[v]) {
        if (!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int x, y; cin >> x >> y; 
        xLevel[x].emplace_back(y);
        yLevel[y].emplace_back(x);
        id[mp(x, y)] = i;
    }

    for (auto [k, v] : xLevel) {
        for (int i = 0; i < v.size(); i += 2) {
            int a = id[mp(k, v[i])];
            int b = id[mp(k, v[i+1])];
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
    }

    for (auto [k, v] : yLevel) {
        for (int i = 0; i < v.size(); i += 2) {
            int a = id[mp(v[i], k)];
            int b = id[mp(v[i+1], k)];
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
    }

    dfs(0); // this sets all the distances
    
    vector<int> delta(p);
    for (int i = 0; i < n; i++) {
        int q, w, e, r; cin >> q >> w >> e >> r;
        int a = id[mp(q, w)], b = id[mp(e, r)];
        if (a > b) swap(a, b);

        int regDist = abs(a-b);
        if (regDist <= p/2) {
             // take the a->b regular route witout the need to wrap around
             if (b != p-1) delta[b+1]--;
             delta[a]++;
        }
        else {
            // take the b->p-1 route and then take the 0->a route
            delta[b]++;
            delta[0]++;
            delta[a+1]--;
        }
    }
    
    for (int i = 0; i < p; i++) {
        dbg(nodeNum[i]);
    }
    // psums the delta array
    for (int i = 1; i < n; i++) {
        delta[i] += delta[i-1];
    }

    for (int i = 0; i < p; i++) {
        cout << delta[nodeNum[i]] << "\n";
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
