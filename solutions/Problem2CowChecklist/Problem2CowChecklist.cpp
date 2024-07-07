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
using pll = pair<ll, ll>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG

#define mp make_pair

const int MAXH = 1001;
const ll INF = 10000000000000;

ll dp[MAXH][MAXH][2];
pll holsteins[MAXH], guernseys[MAXH];

ll dist (pll p1, pll p2) {
    ll ret = (abs(p1.first-p2.first) * abs(p1.first-p2.first)) + (abs(p1.second-p2.second) * abs(p1.second-p2.second));
    return ret;
}

int h, g;
void solve() {
    cin >> h >> g;
    for (int i = 1; i <= h; i++) {
        ll x, y; cin >> x >> y;
        holsteins[i] = mp(x, y);
    }

    for (int i = 1; i <= g; i++) {
        ll x, y; cin >> x >> y;
        guernseys[i] = mp(x, y);
    }
    
    for (int i = 1; i <= g; i++) {
        dp[0][i][0] = dp[0][i][1] = INF;
        dp[i][0][1] = INF;
    }
    dp[1][1][0] = INF;
    dp[1][1][1] = dist(holsteins[1], guernseys[1]);
    for (int hdone = 1; hdone <= h; hdone++) {
        for (int gdone = 1; gdone <= g; gdone++) {
            // 0 means that @h cow
            dp[hdone][gdone][0] = min(
                    dp[hdone-1][gdone][0]+dist(holsteins[hdone-1], holsteins[hdone]),
                    dp[hdone-1][gdone][1]+dist(guernseys[gdone], holsteins[hdone]));
            dp[hdone][gdone][1] = min(
                    dp[hdone][gdone-1][0]+dist(holsteins[hdone], guernseys[gdone]),
                    dp[hdone][gdone-1][1]+dist(guernseys[gdone-1], guernseys[gdone]));
        }
    }
    
    cout << dp[h][g][0] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
