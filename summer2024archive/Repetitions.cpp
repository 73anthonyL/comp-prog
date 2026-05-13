#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

string s;
void solve() {
    cin >> s;
    char l = '0';
    int ans = 1;
    int ct = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!i) {
            ct++;
        }
        if (l == s[i]) {
            ct++;
        }
        else {
            ct = 1;
        }
        l = s[i];
        ans = max(ans, ct);
    }

    cout << ans << "\n";
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
