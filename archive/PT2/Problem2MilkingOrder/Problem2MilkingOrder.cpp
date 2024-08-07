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

const int MAXN = 100001;
const int MAXM = 50000;

int n, m;
vector<vector<int>> O;
vector<int> adj[MAXN];
int indegree[MAXN];
bool vis[MAXN];
vector<int> topo;

bool consistentWithFirst(int x) {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        indegree[i] = 0;
        vis[i] = false;
        topo.clear();
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < O[i].size()-1; j++) {
            adj[O[i][j]].emplace_back(O[i][j+1]); 
            indegree[O[i][j+1]]++;
        }
    }
    
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            pq.push(-i);
        }
    }
    
    int processed = 0;
    while (!pq.empty()) {
        int v = pq.top(); pq.pop(); v = -v;
        topo.emplace_back(v);
        processed++;
        for (auto x : adj[v]) {
            indegree[x]--;
            if (!indegree[x]) {
                pq.push(-x);
            }
        }
    }
    
    if (processed < n) {
        return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> curr;
        for (int j = 0; j < k; j++) {
            int a; cin >> a; curr.emplace_back(a);
        }
        O.emplace_back(curr);
    }

    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        if (consistentWithFirst(mid)) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }

    consistentWithFirst(lo);
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            cout << topo[i] << "\n";
            continue;
        }
        cout << topo[i] << " ";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
