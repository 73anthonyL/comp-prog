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

const int MAXN = 101;
int dp[MAXN][MAXN][MAXN];

int n;
void solve() {
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                // if the current day must be a breakout day,
                // the tampered log must read 0 or else there is a difference
                if (arr[k] != 0) {
                    dp[i][j][k] = 
                }
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    //freopen("taming.in", "r", stdin);
    //freopen("taming.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
