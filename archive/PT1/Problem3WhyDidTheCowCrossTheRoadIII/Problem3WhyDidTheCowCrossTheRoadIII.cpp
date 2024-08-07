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

int n;
const int MAXN = 100001;
int t[4*MAXN];

void build(array<int, MAXN> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    //cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << tm << "\n";
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// helper functions

int sum(int l, int r) {
    return sum(1, 0, n-1, l, r);
}

void update(int pos, int new_val) {
    update(1, 0, n-1, pos, new_val);
}

void solve() {
    cin >> n;
    vector<int> seenAt(n+1, -1);
    n *= 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (seenAt[x] == -1) {
            // unmatched insertion
            seenAt[x] = i;
            update(i, 1);
        }
        else {
            update(seenAt[x], 0);
            ans += sum(seenAt[x]+1, i-1);
        }
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
