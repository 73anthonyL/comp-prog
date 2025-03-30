#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long 
#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
void solve() {
    cin >> n;
    int max_so_far = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; 
        if (a < max_so_far) {
            ans += max_so_far-a;
        }
        max_so_far = max(max_so_far, a);
    }
    cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    //cin >> t;
	while (t--) {
		solve();
	}
}
