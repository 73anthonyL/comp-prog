#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 1000001;

ll n;
void solve() {
    cin >> n;
    if (((n*(n+1))/2) % 2) {
        cout << "NO\n";
    }
    else if (n == 3) {
        cout << "YES\n1\n3\n2\n1 2\n";
    }
    else {
        cout << "YES\n";
        ll curr = ((n*(n+1))/2)/2, ct = n;
        while (ct <= curr) {
            curr -= (ct--);
        }

        cout << n-ct+1 << "\n";
        for (ll i = n; i > ct; i--) {
            cout << i << " ";
        }
        cout << curr << "\n";

        cout << n-(n-ct+1) << "\n";
        for (int i = 1; i <= ct; i++) {
            if (i == ct) {
                cout << i << "\n";
                continue;
            }
            if (i != curr) {
                cout << i << " ";
            }
        }
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
