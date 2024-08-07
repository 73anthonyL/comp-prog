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
#define int ll

int l, r;
void solve() {
    cin >> l >> r;
    // figure out the latest number that has the smallest fl(num/3)
    int idx = 0;
    if ((l+1)/3 == l/3) {
        idx++;
    }
    if ((l+2)/3 == l/3) {
        idx++;
    }

    // figure out how many times this number has to be divided by 3 to get to 0
    int K = l+idx;
    int ans = 0;
    while (K > 0) {
        ans++;
        K /= 3;
    }
    
    ans *= 2;
    for (int i = l; i <= r; i++) {
        if (i != l+idx) {
            int K = i;
            while (K > 0) {
                ans++;
                K /= 3;
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
