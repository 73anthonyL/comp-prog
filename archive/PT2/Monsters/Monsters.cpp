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

const int MAXN = 1000;
int dr[] = {INT32_MAX, 0, 0, -1, 1};
int dc[] = {INT32_MAX, -1, 1, 0, 0}; 
string dir = "qLRUD";

int n, m;
char G[MAXN][MAXN];
int M[MAXN][MAXN], U[MAXN][MAXN];
int vis[MAXN][MAXN];
bool mvis[MAXN][MAXN];

vector<pii> monsters; pii start; 

queue<pii> q;

bool ok(int r, int c) {
    return r < n && c < m && r >= 0 && c >= 0;    
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == '#') {
                vis[i][j] = 1;
                mvis[i][j] = true;
            }
            else if (G[i][j] == 'M') {
                monsters.emplace_back(i, j);
            }
            else if (G[i][j] == 'A') {
                start = mp(i, j);
            }
            M[i][j] = U[i][j] = INT32_MAX;
        }
    }
    
    q.push(start);
    vis[start.first][start.second] = 1;
    U[start.first][start.second] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 1; i <= 4; i++) {
            if (ok(r+dr[i], c+dc[i]) && !vis[r+dr[i]][c+dc[i]]) {
                vis[r+dr[i]][c+dc[i]] = i; 
                U[r+dr[i]][c+dc[i]] = U[r][c]+1;
                q.push(mp(r+dr[i], c+dc[i]));
            }
        }
    }
    
    for (auto p : monsters) {
        q.push(p);
        M[p.first][p.second] = 0;
        mvis[p.first][p.second] = true;
    }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 1; i <= 4; i++) {
            if (ok(r+dr[i], c+dc[i]) && !mvis[r+dr[i]][c+dc[i]]) {
                mvis[r+dr[i]][c+dc[i]] = true;
                M[r+dr[i]][c+dc[i]] = M[r][c]+1;
                q.push(mp(r+dr[i], c+dc[i]));
            }
        }
    }
    
    // iterate through all the boundary squares
    vector<char> ans;
    pii coord(INT32_MAX, INT32_MAX);
    for (int i = 0; i < n; i++) {
        if (G[i][0] != '#' && U[i][0] < M[i][0]) {
            coord = mp(i, 0);
        }
        if (G[i][m-1] != '#' && U[i][m-1] < M[i][m-1]) {
            coord = mp(i, m-1);
        }
    }
   
    for (int i = 0; i < m; i++) {
        if (G[0][i] != '#' && U[0][i] < M[0][i]) {
            coord = mp(0, i);
        }
        if (G[n-1][i] != '#' && U[n-1][i] < M[n-1][i]) {
            coord = mp(n-1, i);
        }
    }
    
    if (coord != mp(INT32_MAX, INT32_MAX)) {
        while (coord != start) {
            ans.emplace_back(dir[vis[coord.first][coord.second]]);
            coord = mp(coord.first-dr[vis[coord.first][coord.second]], coord.second-dc[vis[coord.first][coord.second]]);
        }
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        for (int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << "\n";
        return;     
    }
    cout << "NO" << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
