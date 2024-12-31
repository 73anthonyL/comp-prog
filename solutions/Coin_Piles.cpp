#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int a, b;
void solve() {
    cin >> a >> b;
    if (b < a) swap(a, b);
    if (a >= (b-a)) {
        a -= (b-a);
        b = a;
    }
    else {
        cout << "NO" << "\n";
        return;
    }

    cout << ((a%3) ? "NO\n" : "YES\n");
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
