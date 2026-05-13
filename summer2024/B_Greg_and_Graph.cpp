#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 501;
const ll INF = 500000000;

ll minDist[MAXN][MAXN];

int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> minDist[i][j];
        }
    }

    vector<int> addingOrder(n+1);
    for (int i = n; i > 0; i--) {
        cin >> addingOrder[i];
    }

    // every time you introduce a node you have to add all the edges associated with it (done)
    // skip iteration if i or j equals addingOrder[k]
    // skip iteration if i or j is not in the graph currently]
    vector<ll> ans;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                minDist[i][j] = min(minDist[i][j], minDist[i][addingOrder[k]]+minDist[addingOrder[k]][j]);
            }
        }

        ll sum_of_shortest_paths = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                sum_of_shortest_paths += minDist[addingOrder[i]][addingOrder[j]];
            }
        }
        ans.emplace_back(sum_of_shortest_paths);
    }
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
