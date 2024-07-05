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

int n;
void solve() {
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int> (6));
    for (int i = 1 ; i <= n; i++) {
        // the first can be anything
        if (i == 1) {
            for (int j = 1; j <= 5; j++) {
                dp[i][j] = 1;
            }
            continue;
        }

        int diff = arr[i]-arr[i-1];
        if (!diff) {
            for (int k = 1; k <= 5; k++) {
                if (dp[i-1][k]) {
                    for (int l = 1; l <= 5; l++) {
                        if (l != k) {
                            dp[i][l] = k;
                        }
                    }
                }
            }
        }
        else if (diff < 0) {
            for (int k = 2; k <= 5; k++) {
                if (dp[i-1][k]) {
                    for (int l = k-1; l >= 1; l--) {
                        dp[i][l] = k;
                    }
                }
            }
        }
        else {
            for (int k = 1; k <= 4; k++) {
                if (dp[i-1][k]) {
                    for (int l = k+1; l <= 5; l++) {
                        dp[i][l] = k;
                    }
                }
            }
        }
    }
    
    int pathTail = 0;
    for (int i = 1; i <= 5; i++) {
        if (dp[n][i]) {
            pathTail = i;
        }
    }

    if (!pathTail) {
        cout << -1 << "\n";
        return;
    }

    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        ans.emplace_back(pathTail);
        pathTail = dp[i][pathTail];
    }

    for (int i = n-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
