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
#include <cassert>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG

#define mp make_pair

const int MAXH = 1001;
const ll INF = (1L<<60);

ll dp[MAXH][MAXH][2];
pll holsteins[MAXH], guernseys[MAXH];

ll dist (pll p1, pll p2) {
    ll ret = ((p1.first-p2.first) * (p1.first-p2.first)) + ((p1.second-p2.second) * (p1.second-p2.second));
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
    
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= g; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[1][0][0] = 0;

    for (int hdone = 0; hdone <= h; hdone++) {
        for (int gdone = 0; gdone <= g; gdone++) {
            for (int endG = 0; endG < 2; endG++) {
                if ((!endG && !hdone) || (endG && !gdone)) continue;
                pll source = ((endG) ? guernseys[gdone] : holsteins[hdone]);

                if (gdone < g) {
                    dp[hdone][gdone+1][1] = min(dp[hdone][gdone+1][1], dist(source, guernseys[gdone+1])+dp[hdone][gdone][endG]);
                }

                if (hdone < h) {
                    dp[hdone+1][gdone][0] = min(dp[hdone+1][gdone][0], dist(source, holsteins[hdone+1])+dp[hdone][gdone][endG]);
                }
            }
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
