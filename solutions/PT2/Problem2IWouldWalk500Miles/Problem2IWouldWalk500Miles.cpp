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

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 7501;
const ll INF = 2019201998;

int n, k;
ll minEdge[MAXN];
vector<ll> mstEdges;

ll dist(ll x, ll y) {
    if (x > y) swap(x, y);
    return (2019201913LL*x+2019201949LL*y) % 2019201997;
}

void solve() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            minEdge[i] = INT32_MAX;
            continue;
        }
        minEdge[i] = dist(1, i);
    }

    for (int i = 0; i < n-1; i++) {
        int closestV; ll edgeLength = INT32_MAX;
        for (int j = 2; j <= n; j++) {
            if (minEdge[j] < edgeLength) {
                edgeLength = minEdge[j];
                closestV = j;
            }
        }
        mstEdges.emplace_back(edgeLength);
        minEdge[closestV] = INT32_MAX;

        for (int j = 2; j <= n; j++) {
            if (minEdge[j] != INT32_MAX) {
                minEdge[j] = min(minEdge[j], dist(j, closestV));
            }
        }
    }

    sort(mstEdges.begin(), mstEdges.end(), greater<>());
    cout << mstEdges[n-k-1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
