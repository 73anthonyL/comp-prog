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
using pil = pair<int, ll>;
using pli = pair<ll, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 10001;
const ll INF = 250000001;

int n, m; ll T;
vector<pil> adj[MAXN];
priority_queue<pli> pq;
bool vis[MAXN];
int from[MAXN], parentsOf[MAXN];
ll dist[MAXN], passThrough[MAXN];

void dfs_pass(int v) {
    if (from[v]) {
        passThrough[from[v]] += passThrough[v];
    }
}

void solve() {
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++) {
        cin >> passThrough[i];
        dist[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    
    dist[1] = 0;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        auto [z, v] = pq.top();
        pq.pop();
        z = -z;
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [nei, w] : adj[v]) {
            if (z+w < dist[nei]) {
                dist[nei] = z+w;
                from[nei] = v;
                pq.push(mp(-dist[nei], nei));
                parentsOf[v]++;
            }
            else if (z+w == dist[nei]) {
                if (v < from[nei]) {
                    parentsOf[from[nei]]--;
                    from[nei] = v;
                    parentsOf[v]++;
                    pq.push(mp(-z-w, nei));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!parentsOf[i]) {
            dfs_pass(i);
        }
    }
    
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        if (T < dist[i]) {
            ans = max(ans, passThrough[i]*(dist[i]-T));
        }
    }

    cout << ans << "\n";
}
// $f(v) = numOfCowsThatPassThrough*distFromBarn\[v\]$

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    /* freopen("shortcut.in", "r", stdin); */
    /* freopen("shortcut.out", "w", stdout); */

	int t = 1;
	while (t--) {
		solve();
	}
}