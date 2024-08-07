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

const int MOD = 1e9 + 7;
const int MAXN = 100001;

int n, k;
vector<int> adj[MAXN];
vector<int> C(MAXN);
vector<vector<ll>> dp(MAXN, vector<ll> (3, 0));

ll memo(int v, int color, int p) {
    if (dp[v][color]) return dp[v][color];
    if (C[v] && C[v]-1 != color) {
        dp[v][color] = 0;
        return dp[v][color];
    }
    dp[v][color] = 1;
    for (auto x : adj[v]) {
        // skip if you go back to the parent
        if (x == p) continue;
        // go through all 3 of the possible colors
        ll curr = 0;
        for (int i = 0; i < 3; i++) {
            // add up 
            if (i == color) continue;
            curr += memo(x, i, v);
            curr %= MOD;
        }
        dp[v][color] *= curr;
        dp[v][color] %= MOD;
    }
    return dp[v][color];
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    // root at the first possible one 
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        cin >> C[a];
    }
    
    cout << (memo(1, 0, -1)+memo(1, 1, -1)+memo(1, 2, -1))%MOD << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
