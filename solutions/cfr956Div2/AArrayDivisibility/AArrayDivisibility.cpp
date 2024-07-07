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

ll n;
void solve() {
    cin >> n;
    vector<ll> ans(n+1);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (j%i == 0) {
                if (!ans[j]) {
                    ans[j] = i;
                }
                else {
                    ans[j] = lcm(ans[j], i);
                }
            }
        }
    }

    for (auto x : ans) {
        if (x!=0) {
            cout << x << " ";
        }
    }
    cout << "\n";
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
