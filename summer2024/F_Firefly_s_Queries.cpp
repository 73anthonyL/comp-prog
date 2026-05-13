#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

// calculate total sum of all the full arrays, then figure out
// from where to where are the partials

ll fireflyQuery(int idxl, int idxr, int shifts, vector<ll> &psums) {
    
}

int n, q;
void solve() {
    cin >> n >> q;
    vector<ll> A(n), P(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        P[i] = ((!i) ? A[i] : A[i-1]+A[i]);
    }

    // 1, n+1, 2n+1, 3n+1 <- startpoints
    // n, 2n, 3n, 4n, 5n, 6n <- endpoints

    // n == 3
    // 1 2 3, 4 5 6, 7 8 9, 10 11 12
    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = 0;
        // calculate the full segments
        ll highestL = (((l+n-1)/n)*n)+1;
        ll lowestR = (r/n)*n;
        if (highestL < lowestR) {
            ans += ((lowestR-highestL+1)/n)*P[n-1];
        }

        // calculate the partials
        // from l to highestL

        // from lowestR to r
    }
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
