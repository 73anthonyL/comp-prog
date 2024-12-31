#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int q;
void solve() {
    cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        ll k = max(a, b);
        ll c = 1+((k-1)*k);
        if (a == b) {
            cout << c << "\n";
        }
        else {
            if (a < k) {
                cout << ((k%2) ? c+(k-a) : c-(k-a)) << "\n";
            }
            else {
                cout << ((k%2) ? c-(k-b) : c+(k-b)) << "\n";
            }
        }
    }
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
