#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <bitset>
#include <iomanip>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200001;
array<ll, MAXN> A;
array<ll, 4*MAXN> T;

ll build(int v, array<ll, MAXN> &A, int repl, int repr) {
    if (repl == repr) {
        T[v] = A[repl];
        return T[v];
    }
    int tl = v*2, tr = (v*2)+1;
    T[v] = build(tl, A, repl, (repl+repr)/2) + build(tr, A, ((repl+repr)/2)+1, repr);
    return T[v];
}

ll sum(int v, int repl, int repr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (repl == l && repr == r) {
        return T[v];
    }
    return sum(v*2, repl, (repl+repr)/2, l, min(r, (repl+repr)/2)) + sum(v*2+1, ((repl+repr)/2)+1, repr, max(l, ((repl+repr)/2)+1), r);
}

void update(int v, int repl, int repr, int pos, ll newVal) {
    if (repl == repr) {
        T[v] = newVal;
        return;
    }
    if (repl <= pos && (repl+repr)/2 >= pos) {
        update(v*2, repl, (repl+repr)/2, pos, newVal);
    }
    if (((repl+repr)/2)+1 <= pos && pos <= repr) {
        update(v*2+1, ((repl+repr)/2)+1, repr, pos, newVal);
    }
    T[v] = T[v*2]+T[v*2+1];
}

int n, q;
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    build(1, A, 0, n-1); 

    int type;
    while (q--) {
        cin >> type;
        if (type == 1) {
            int k; ll u; cin >> k >> u;
            update(1, 0, n-1, k-1, u);
        }
        else {
            int a, b; cin >> a >> b;
            cout << sum(1, 0, n-1, a-1, b-1) << "\n";
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
