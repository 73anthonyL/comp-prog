#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 500001; // 5e5

int n;
vector<int> A(MAXN), idxOfMinRight(MAXN), maxLeft(MAXN);
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) {
            idxOfMinRight[i] = i;
            continue;
        }
        if (A[i] < A[idxOfMinRight[i+1]]) {
            idxOfMinRight[i] = i;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (!i) {
            maxLeft[i] = A[i];
            continue;
        }
        maxLeft[i] = max(maxLeft[i-1], A[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            cout << maxLeft[idxOfMinRight[i]] << "\n";
            continue;
        }
        cout << maxLeft[idxOfMinRight[i]] << " ";
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
