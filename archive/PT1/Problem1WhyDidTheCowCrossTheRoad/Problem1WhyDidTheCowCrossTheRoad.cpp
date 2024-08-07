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
#define int long long 
#define mp make_pair

const int MAXN = 100;
const int INF = INT32_MAX;

int g[MAXN][MAXN];
int dist[MAXN][MAXN];
bool proc[MAXN][MAXN];
priority_queue<array<int, 3>> q;

int dr[] = {3, -3, 2, -2, 1, -1, 0, 2, -2, -1, 1, 0, 0, 0, 1, -1};
int dc[] = {0, 0, 1, 1, 2, 2, 3, -1, -1, -2, -2, -3, -1, 1, 0, 0};

int n, T; 
bool ok(int r, int c) {
    return r < n && c < n && r >= 0 && c >= 0;
}

int manDist(int r1, int c1, int r2, int c2) {
    int ret = abs(r1-r2)+abs(c1-c2);
    return ret;
}

void solve() {
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            dist[i][j] = INF;
        }
    }
    
    q.push({0, 0, 0});
    while(!q.empty()) {
        auto [val, r, c] = q.top(); q.pop();
        if (proc[r][c]) continue;
        proc[r][c] = true;
        if (manDist(r, c, n-1, n-1) < 3) {
            if (-val+(T*manDist(r, c, n-1, n-1)) < dist[n-1][n-1]) {
                dist[n-1][n-1] = -val+(T*manDist(r, c, n-1, n-1));
            }
            continue;
        }

        for (int i = 0; i < 16; i++) {
            if (ok(r+dr[i], c+dc[i]) && -val+(3*T)+g[r+dr[i]][c+dc[i]] < dist[r+dr[i]][c+dc[i]]) {
                dist[r+dr[i]][c+dc[i]] = -val+(3*T)+g[r+dr[i]][c+dc[i]];
                q.push({-dist[r+dr[i]][c+dc[i]], r+dr[i], c+dc[i]});
            }
        }
    }

    cout << dist[n-1][n-1] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
