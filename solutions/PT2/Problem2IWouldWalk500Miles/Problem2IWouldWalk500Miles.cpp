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

const int MAXN = 7501;
const ll INF = 2019201998;

int n, k;
ll D[MAXN];
vector<ll> EW;

ll dist(ll x, ll y) {
    if (x > y) swap(x, y);
    return (2019201913LL*x+2019201949LL*y) % 2019201997LL;
}

void solve() {
    cin >> n >> k;
    D[1] = INF;
    for (int i = 2; i <= n; i++) {
        D[i] = dist(1, i); 
    }

    for (int i = 0; i < n-1; i++) {
        ll min_j = -1;
        for (int j = 2; j <= n; j++) {
            if (min_j == -1 || D[min_j] > D[j]) {
                min_j = j;
            }
        }

        EW.emplace_back(D[min_j]);
        D[min_j] = INF;

        for (int j = 2; j <= n; j++) {
            if (D[j] != INF) {
                D[j] = min(D[j], dist(min_j, j));
            }
        }
    }

    sort(EW.begin(), EW.end());
    cout << EW[n-k] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /* freopen("walk.in", "r", stdin); */
    /* freopen("walk.out", "w", stdout); */

	int t = 1;
	while (t--) {
		solve();
	}
}
