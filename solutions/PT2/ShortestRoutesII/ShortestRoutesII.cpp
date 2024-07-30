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

const int MAXN = 501;
const ll INF = 500000000000;

int n, m, q;
ll adj[MAXN][MAXN], dist[MAXN][MAXN];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b; ll c; cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = (adj[a][b]) ? min(adj[a][b], c) : c;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (adj[i][j]) {
                dist[i][j] = dist[j][i] = adj[i][j];
                continue;
            }
            dist[i][j] = dist[j][i] = INF;
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); 
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << ((dist[a][b] == INF) ? -1 : dist[a][b]) << "\n";
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
