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
    cerr << #v << " = " << (v) << "\n";
    
int n;
void solve() {
    cin >> n;
    vector<int> flh(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> flh[i];
    }

    vector<int> dp(n+1);
    dp[n] = flh[n];

    for (int i = n-1; i >= 1; i--) {
        dp[i] = max(dp[i+1]+1, flh[i]);
    }
    
    cout << dp[1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
