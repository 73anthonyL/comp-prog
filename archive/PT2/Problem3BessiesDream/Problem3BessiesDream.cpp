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

const int MAXN = 1001;

int n, m;
int G[MAXN][MAXN];
int dp[MAXN][MAXN][2][5];
int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, -1, 1, 0, 0};
deque<array<int, 4>> q;

bool ok(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    dp[0][0][0][0] = 1;
    q.push_back({0, 0, 0, 0});
    while (!q.empty()) {
        auto [r, c, o, sli] = q.front(); q.pop_front();
        // if currently sliding
        if (sli) {
            if (!ok(r+dr[sli], c+dc[sli]) || !G[r+dr[sli]][c+dc[sli]] || G[r+dr[sli]][c+dc[sli]] == 3) {
                if (!dp[r][c][o][0]) {
                    dp[r][c][o][0] = dp[r][c][o][sli];
                    q.push_front({r, c, o, 0});
                }
            }
            else if (G[r+dr[sli]][c+dc[sli]] == 4) {// if continue to slide
                if (!dp[r+dr[sli]][c+dc[sli]][0][sli]) {
                    dp[r+dr[sli]][c+dc[sli]][0][sli] = dp[r][c][o][sli]+1;
                    q.push_back({r+dr[sli], c+dc[sli], 0, sli});
                }
            }
            else {
                // slide into this tile
                int next_o = (G[r+dr[sli]][c+dc[sli]] == 2) ? 1|o : 0|o;
                if (!dp[r+dr[sli]][c+dc[sli]][next_o][0]) {
                    dp[r+dr[sli]][c+dc[sli]][next_o][0] = dp[r][c][o][sli]+1;
                    q.push_back({r+dr[sli], c+dc[sli], next_o, 0});
                }
            }
            continue;
        }
        for (int i = 1; i <= 4; i++) {
            if (ok(r+dr[i], c+dc[i]) && G[r+dr[i]][c+dc[i]]) {
                if (G[r+dr[i]][c+dc[i]] == 4) { // this next tile will be a sliding one
                    if (!dp[r+dr[i]][c+dc[i]][0][i]) {
                        dp[r+dr[i]][c+dc[i]][0][i] = dp[r][c][o][sli]+1;
                        q.push_back({r+dr[i], c+dc[i], 0, i});
                    }
                }
                else {
                    int next_o = (G[r+dr[i]][c+dc[i]] == 2) ? 1|o : 0|o;
                    if (G[r+dr[i]][c+dc[i]] == 3) {
                        if (o) {
                            if (!dp[r+dr[i]][c+dc[i]][1][0]) {
                                dp[r+dr[i]][c+dc[i]][1][0] = dp[r][c][o][sli]+1;
                                q.push_back({r+dr[i], c+dc[i], 1, 0});
                            }
                        }
                    }
                    else {
                        if (!dp[r+dr[i]][c+dc[i]][next_o][0]) {
                            dp[r+dr[i]][c+dc[i]][next_o][0] = dp[r][c][o][0]+1;
                            q.push_back({r+dr[i], c+dc[i], next_o, 0});
                        }
                    }
                }
                 
            }
        }
    }
    
    int ans = INT32_MAX;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            if (dp[n-1][m-1][i][j]) {
                ans = min(ans, dp[n-1][m-1][i][j]-1);
            }
        }
    }

    cout << ((ans == INT32_MAX) ? -1 : ans) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
