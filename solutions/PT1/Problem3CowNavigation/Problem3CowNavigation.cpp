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

#define mp make_pair

const int MAXN = 20;
char g[MAXN][MAXN];
int vis[MAXN][MAXN][4][MAXN][MAXN][4];
queue<array<int, 6>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int right(int dir) {
    return (dir-1+4)%4;
}

int left(int dir) {
    return (dir+1)%4;
}

int n;
bool ok(int x, int y) {
    return x < n && y < n && x >= 0 && y >= 0 && g[x][y] != 'H';
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[j][n-i-1];
        }
    }

    q.push({0, 0, 0, 0, 0, 1});
    vis[0][0][0][0][0][1] = 1;
    bool first = true;
    while(!q.empty()) {
        auto [x1, y1, d1, x2, y2, d2] = q.front(); q.pop();
        bool oneThere = (x1 == n-1) && (y1 == n-1), twoThere = (x2 == n-1) && (y2 == n-1);
        if (oneThere && twoThere) {
            cout << vis[x1][y1][d1][x2][y2][d2]-1 << "\n";
            return;
        }
        if (!vis[x1][y1][right(d1)][x2][y2][right(d2)]) {
            vis[x1][y1][right(d1)][x2][y2][right(d2)] = vis[x1][y1][d1][x2][y2][d2]+1;
            q.push({x1, y1, right(d1), x2, y2, right(d2)});
        }
        
        if (!vis[x1][y1][left(d1)][x2][y2][left(d2)]) {
            vis[x1][y1][left(d1)][x2][y2][left(d2)] = vis[x1][y1][d1][x2][y2][d2]+1;
            q.push({x1, y1, left(d1), x2, y2, left(d2)});
        }
        
        // check if its ok to go forward on the first possible direction cow
        // if so, march forward with it
        int nx1, ny1, nx2, ny2;
        if (ok(x1+dx[d1], y1+dy[d1]) && !oneThere) {
            nx1 = x1+dx[d1];
            ny1 = y1+dy[d1];
        }
        else {
            // stays in the same square
            nx1 = x1;
            ny1 = y1;
        }

        if (ok(x2+dx[d2], y2+dy[d2]) && !twoThere) {
            nx2 = x2+dx[d2];
            ny2 = y2+dy[d2];
        }
        else {
            // stays in the same square
            nx2 = x2;
            ny2 = y2;
        }

        if (!vis[nx1][ny1][d1][nx2][ny2][d2]) {
            q.push({nx1, ny1, d1, nx2, ny2, d2});
            vis[nx1][ny1][d1][nx2][ny2][d2] = vis[x1][y1][d1][x2][y2][d2]+1;
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
	int t = 1;
	while (t--) {
		solve();
	}
}
