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
#define int long long
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
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void increment(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        cerr << "same " << tl << " " << tr << "\n";
        t[v]++;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            increment(v*2, tl, tm, pos);
        else
            increment(v*2+1, tm+1, tr, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// helper functions

int sum(int l, int r) {
    return sum(1, 0, n, l, r);
}

void increment(int pos) {
    increment(1, 0, n, pos);
}

void solve() {
    cin >> n;
    vector<int> C(n+1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int curr = sum(a+1, n);
        C[a] += curr;
        increment(a);
    }
    
    for (int i = 1; i <= n; i++) {
        C[i] += C[i-1];
    }
    
    cout << 0 << "\n";
    for (int i = 0; i < n-1; i++) {
        cout << C[i] << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
