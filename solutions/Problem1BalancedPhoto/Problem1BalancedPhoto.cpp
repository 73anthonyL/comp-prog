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
#include <cassert>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
const int MAXN = 100001;
int t[4*MAXN];
array<int, MAXN> proc;

void build(array<int, MAXN> a, int v, int tl, int tr) {
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

int sum(int l, int r) {
    return sum(1, 0, n-1, l, r);
}

void update(int pos, int new_val) {
    update(1, 0, n-1, pos, new_val);
}

void solve() {
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int z; cin >> z; a[i] = mp(z, i);
    }
    
    sort(a.begin(), a.end(), greater<pii>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int totalProcessed = i;
        int L_i = sum(0, a[i].second-1);
        int R_i = sum(a[i].second+1, n-1);

        if (L_i > 2*R_i || R_i > 2*L_i) {
            ans++;
        }

        update(a[i].second, 1);
    }

    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
