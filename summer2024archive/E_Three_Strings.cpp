#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 1001;
int dp[MAXN][MAXN];

string a, b, c;
void solve() {
    cin >> a >> b >> c;
    for (int i = 1; i <= a.size(); i++) {
        dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
    }
    for (int j = 1; j <= b.size(); j++) {
        dp[0][j] = dp[0][j-1] + (b[j-1] != c[j-1]);
    }

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            dp[i][j] = min(dp[i-1][j] + (a[i-1] != c[i+j-1]), dp[i][j-1] + (b[j-1] != c[i+j-1]));
            // cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }

    cout << dp[a.size()][b.size()] << "\n";
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
