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
    while (n != 1) {
        cout << n << " ";
        n = ((n%2) ? (n*3)+1 : n/2);
    } 
    cout << 1 << "\n";
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
