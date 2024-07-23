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

const int MAXN = 200002;
int type(char c) {
    if (c == 'L') return 0;
    else if (c == 'W') return 1;
    else return 2;
}

int dp[MAXN];
int n, m, k;
string s;
void solve() {
    cin >> n >> m >> k;
    vector<int> path(n+2);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c; path[i] = type(c);
        dp[i] = 0;
    }
    dp[n+1] = 0;

    int pt = 1;
    path[0] = 0;
    dp[0] = k+1;
    path[n+1] = 3;
    for (int i = 0; i <= n; i++) {
        if (dp[i] >= 1) {
            if (path[i] == 0) {
                for (int j = 1; j <= m; j++) {
                    if (i+j <= n+1 && path[i+j] != 2) {
                        dp[i+j] = dp[i];
                        if (i+j == n+1) {
                            cout << "YES\n";
                            return;
                        }
                    }
                }
            }
            else if (path[i] == 1) {
                if (i+1 <= n+1 && path[i+1] != 2 && dp[i] >= 2) {
                    dp[i+1] = max(dp[i+1], dp[i]-1);
                    if (i+1 == n+1) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    
    cout << "NO" << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
        dbg(t);
		solve();
	}
}
