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
const int MAXN = 251;
const ll INF = 250000000;

int n; ll w;
void solve() {
    cin >> n >> w;
    vector<pii> A(n+1);
    int maxT = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
        maxT += A[i].second;
    }
    
    //cout << n+1 << " " << maxT+1 << " " << INF << "\n";
    vector<vector<int>> dp(n+1, vector<int> (maxT+1, INF));
    
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        // minimum weight of collections of cows that add up to specific T 
        for (int j = 0; j <= maxT; j++) {
            if (j-A[i].second >= 0) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-A[i].second]+A[i].first);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    ll bestRatio = 0;
    for (int i = 0; i <= maxT; i++) {
        if (dp[n][i] != INF && dp[n][i] >= w) {
            bestRatio = max(bestRatio, ((ll)1000*i)/(dp[n][i]));
        }
    }
    cout << bestRatio << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
