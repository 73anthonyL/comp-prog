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
    for (ll i = 1; i <= n; i++) {
        ll totWays = ((i*i)*((i*i)-1))/2;
        ll rectangles = 2*max(i-3+1, (ll)0)*max(i-2+1, (ll)0);
        cout << totWays-(2*rectangles) << "\n";
    }
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
