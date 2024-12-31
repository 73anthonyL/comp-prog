#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const ll MOD = 1e9+7;
ll n;

void solve() {
    cin >> n;
    ll ans = 1;
    while (n--) {
        ans*=2;
        ans%=MOD;
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    // ci >> t;
	while (t--) {
		solve();
	}
}
