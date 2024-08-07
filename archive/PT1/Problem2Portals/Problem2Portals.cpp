#define _GLIBCXX_DEBUG
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
using pli = pair<ll, int>;
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

struct DSU {
    vector<int> e;
    DSU(int n) { e = vector<int>(n, -1); }
    int get(int x) { 
        return e[x] < 0 ? x : e[x] = get(e[x]); 
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y], e[y] = x;
        return true;
    }
};

int n;
void solve() {
    cin >> n;
    vector<tuple<ll, int, int>> edgeList;
    DSU uf(2*n);
    for (int i = 0; i < n; i++) {
        ll c; cin >> c;
        int w, x, y, z; cin >> w >> x >> y >> z;
        uf.unite(w-1, x-1); uf.unite(y-1, z-1);
        edgeList.emplace_back(c, w-1, y-1);
    }
    sort(edgeList.begin(), edgeList.end());
    
    ll ans = 0;
    for (int i = 0; i < edgeList.size(); i++) {
        if (uf.unite(get<1>(edgeList[i]), get<2>(edgeList[i]))) {
            ans += get<0>(edgeList[i]);
        }
    }

    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
