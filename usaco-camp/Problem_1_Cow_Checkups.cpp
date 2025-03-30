#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 500001;
int n;
int A[MAXN], B[MAXN];
ll rightOne[MAXN];
map<int, ll>  occurrences;

ll summation(ll a) {
    return a*(a+1)/2;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }


    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            // calculate the amount of times this specific cow stays
            ll left = i, right = n-i-1;
            rightOne[i] += (summation(left) + summation(right) + min(left, right));
            cout << left << " " << right << " " << min(left, right) << " " << rightOne[i] << "\n";
        }
        occurrences[A[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += rightOne[i]+occurrences[B[i]];
        cout << B[i] << " " << occurrences[B[i]] << "\n";
    }

    cout << ans << "\n";
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
