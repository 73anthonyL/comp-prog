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

const int MAXN = 1001;
int dp[MAXN][MAXN];

int n;
void solve() {
    cin >> n;
    vector<int> A(n+1), B(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            // if (i, j) pair is friendly
            if (abs(A[i]-B[j]) <= 4) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1); 
            }
        }
    }
    
    cout << dp[n][n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
