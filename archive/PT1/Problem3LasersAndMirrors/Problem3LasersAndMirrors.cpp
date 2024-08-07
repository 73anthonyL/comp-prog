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
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG
#define mp make_pair

int n, xl, yl, xb, yb;
unordered_map<int, vector<int>> xLevel, yLevel;
set<pii> vis; // first indicates val, second indicates x or a y (x = 0, y = 1)
queue<array<int, 3>> q; // bfs queue {val, dist, type}
void solve() {
    cin >> n;
    pii beam, destination;
    for (int i = 0; i < n+2; i++) {
        int x, y; cin >> x >> y;
        if (i == 0) beam = mp(x, y);
        if (i == 1) destination = mp(x, y);
        xLevel[x].emplace_back(y);
        yLevel[y].emplace_back(x);
    }

    q.push({beam.first, 0, 0});
    q.push({beam.second, 0, 1});

    while (!q.empty()) {
        auto [val, dist, isY] = q.front(); q.pop();
        if (isY && val == destination.second || !isY && val == destination.first) {
            cout << dist << "\n";
            return;
        }

        vis.insert(mp(val, isY));
        if (isY) {
            for (auto x : yLevel[val]) {
                if (vis.find(mp(x, !isY)) == vis.end()) {
                    q.push({x, dist+1, !isY});
                }
            }
        }
        else {
            for (auto y : xLevel[val]) {
                if (vis.find(mp(y, !isY)) == vis.end()) {
                    q.push({y, dist+1, !isY});
                }
            }
        }
    }
    
    cout << - 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    
	int t = 1;
	while (t--) {
		solve();
	}
}
