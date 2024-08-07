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

const int MAXN = 1000;
vector<int> adj[MAXN];
ll dp[MAXN][MAXN];

ll n, m, c;
void solve() {
    cin >> n >> m >> c;
    vector<ll> gains(n);
    for (int i = 0; i < n; i++) {
        cin >> gains[i];
        fill(begin(dp[i]), end(dp[i]), INT32_MIN);
    }
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].emplace_back(b);
    }
   
    dp[0][0] = 0;
    // push dp
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != INT32_MIN) {
                for (auto x : adj[j]) {
                    dp[i+1][x] = max(dp[i][j]+gains[x]-(c*((2*i)+1)), dp[i+1][x]);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans = max(ans, dp[i][0]);
    }

    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
