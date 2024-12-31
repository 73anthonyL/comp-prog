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
    ll tot = 0;
    for (ll i = 0; i < n-1; i++) {
        ll a; cin >> a; tot += a;
    }

    cout << (n*(n+1))/2 - tot << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    //cin >> t;
	while (t--) {
		solve();
	}
}
