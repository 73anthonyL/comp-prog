#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <math.h>
#include <numeric>
#include <set>
#include <cstdint>
#include <string>
#include <map>
#include <bitset>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int n, m, k;

bool ok(int r, int c) {
    return r <= n && c <= m && r > 0 && c > 0;
}

int ct = 1;
map<pii, int> ccid;
int ff(int r, int c, vector<vector<bool>> &g, vector<vector<bool>> &vis) {
    int contri = 0;
    ccid[make_pair(r, c)] = ct;
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        if (ok(r+dr[i], c+dc[i])) {
            // if neighbor in g is false then it is a painting contributed
            if (!g[r+dr[i]][c+dc[i]]) {
                contri++;
            }
            else if (!vis[r+dr[i]][c+dc[i]]) {
                contri += ff(r+dr[i], c+dc[i], g, vis);
            }
        }
    }

    return contri;
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<bool>> g(n+1, vector<bool> (m+1));
    vector<vector<bool>> vis(n+1, vector<bool> (m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c; 
            if (c == '.') {
                g[i][j] = true;
            }
        }
    }
    
    vector<int> ccper = {-1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && g[i][j]) {
                ccper.emplace_back(ff(i, j, g, vis));    
                ct++;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        cout << ccper[ccid[make_pair(a, b)]] << "\n";
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

// answer for starting locs in the same connected component are the same
// ff through all the connected components and assign each coordinate to a cc id (tree map)
// need to figure out how to get the perimeter of a connected component
