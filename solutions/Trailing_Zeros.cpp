#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

ll n;
void solve() {
    cin >> n;
    ll ans = 0;
    for (ll i = 5; i <= n; i*=5) {
        ans += n/i;
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    // cin >> t;
	while (t--) {
		solve();
	}
}
