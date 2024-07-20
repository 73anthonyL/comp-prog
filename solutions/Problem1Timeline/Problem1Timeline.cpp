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
const int MAXN = 100001;

int n, m, c;
int T[MAXN];
bool vis[MAXN];
vector<pii> adj[MAXN];
vector<int> topo;

void dfs(int v) {
    vis[v] = true;
    for (auto x : adj[v]) {
        if (!vis[x.first]) {
            dfs(x.first);
        }
    }
    topo.emplace_back(v);
}

void solve() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < c; i++) {
        int a, b, x; cin >> a >> b >> x;
        adj[a].emplace_back(b, x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i); 
        }
    }

    topo.emplace_back(-1);
    reverse(topo.begin(), topo.end());
     
    for (int i = 1; i < n; i++) {
        // source dp nodes -> run push dp
        for (auto x : adj[topo[i]]) {
            T[x.first] = max(T[x.first], T[topo[i]]+x.second);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << T[i] << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
