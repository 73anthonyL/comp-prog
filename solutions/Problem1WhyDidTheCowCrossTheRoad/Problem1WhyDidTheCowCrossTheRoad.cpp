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

const int MAXN = 100;
int g[MAXN][MAXN];
int dp[MAXN][MAXN][3] = {-1};
queue<array<int, 3>> q;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int prev(int &order) {
    return (order-1+3)%3;
}

int n, t; 
bool ok(int r, int c) {
    return r < n && c < n && r >= 0 && c >= 0;
}

int minTimeToState(int r, int c, int order) {
    if (dp[r][c][order] != -1) {
        // this state has been cached already
        return dp[r][c][order];
    }

    int minNeighbor = INT32_MAX;
    for (int i = 0; i < 4; i++) {
        if (ok(r+dr[i], c+dc[i])) {
            minNeighbor = min(minNeighbor, minTimeToState(r+dr[i], c+dc[i], prev(order)));
        }
    }
    
    dp[r][c][order] = (minNeighbor + ((order == 2) ? g[r][c] : 0) + t);
    return dp[r][c][order];
}

void solve() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    dp[0][0][0] = 0; 
    cout << min(min(minTimeToState(n-1, n-1, 2), minTimeToState(n-1, n-1, 1)), minTimeToState(n-1, n-1, 0)) << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                dbg(dp[i][j][k]);
            }
        }
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
