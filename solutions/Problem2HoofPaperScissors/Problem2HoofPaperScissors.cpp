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
#define dbg(v) \
    cout << #v << " = " << (v) << ", ";

const int MAXN = 100001;
const int MAXK = 21;

// array idx, switches used, target of last gesture used by bessie
int dp[MAXN][MAXK][3];

int n, k;
void solve() {
    cin >> n >> k;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c; 
        // H is 0, P is 1, S is 2
        int bH = (c == 'H') ? 1 : 0;
        int bP = (c == 'P') ? 1 : 0;
        int bS = (c == 'S') ? 1 : 0;
        for (int j = 0; j <= k; j++) {
            if (!j) {
                dp[i][j][0] = dp[i-1][j][0]+bH;
                dp[i][j][1] = dp[i-1][j][1]+bP;
                dp[i][j][2] = dp[i-1][j][2]+bS;
            }
            else {
                dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j-1][1], dp[i-1][j-1][2]))+bH;
                dp[i][j][1] = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][2]))+bP;
                dp[i][j][2] = max(dp[i-1][j][2], max(dp[i-1][j-1][0], dp[i-1][j-1][1]))+bS;
            }
            if (i == n) {
                ans = max(max(ans, dp[i][j][0]), max(dp[i][j][1], dp[i][j][2]));
            }
        }
    }

    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
	int t = 1;
	while (t--) {
		solve();
	}
}
