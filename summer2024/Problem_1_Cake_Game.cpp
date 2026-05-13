#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
void solve() {
    cin >> n;
    vector<ll> psums(n+1), a(n+1);
    psums[0] = a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; psums[i] = psums[i-1]+a[i];
    }

    // (n/2)-1 turns to get from the edge
    // from 0 from the left to (n/2)-1 items from the left
    ll elsie_max = 0;
    for (int l_items = 0; l_items <= (n/2)-1; l_items++) {
        elsie_max = max(elsie_max, psums[l_items]+psums[n]-psums[n-(((n/2)-1)-l_items)]);
    }

    cout << psums[n]-elsie_max << " " << elsie_max << "\n";
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
