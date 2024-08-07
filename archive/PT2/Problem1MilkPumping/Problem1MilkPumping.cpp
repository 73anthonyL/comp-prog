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
#define int long long
const int MAXN = 1001;

int n, m;
vector<pii> adj[MAXN];
vector<tuple<int, int, int, int>> E;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, f; cin >> a >> b >> c >> f; 
        E.emplace_back(f, a, b, c);
    }
    sort(E.begin(), E.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        // add all of the edges into the graph at this level
        int lvl = get<0>(E[i]);
        while (get<0>(E[i]) == lvl && i < m) {
            adj[get<1>(E[i])].emplace_back(get<2>(E[i]), get<3>(E[i]));
            adj[get<2>(E[i])].emplace_back(get<1>(E[i]), get<3>(E[i]));
            i++;
        }
        i--;
         
        // run dijkstra's algorithm on this graph
        vector<int> dist(n+1, 20000000);
        vector<bool> vis(n+1);
        priority_queue<pii> pq;
        pq.push(mp(0, 1));
        vis[1] = true; dist[1] = 0;
        while (!pq.empty()) {
            auto [z, v] = pq.top(); 
            vis[v] = true;
            pq.pop(); z = -z;
            for (auto [nei, w] : adj[v]) {
                if (vis[nei]) continue;
                if (z+w < dist[nei]) {
                    dist[nei] = z+w;
                    pq.push(mp(-dist[nei], nei)); 
                }
            }
        }
        ans = max(ans, (1000000*(lvl))/dist[n]);
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
