#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200001;

int n, q;
vector<int> adj[MAXN];
array<int, 2*MAXN> ET; // Euler Tour
array<int, MAXN> FO; // first occurrence of node in Euler Tour
array<int, MAXN> D; // depth of node in graph
array<array<int, 19>, 2*MAXN> SPARSE;
int ct = 0;

void dfs(int v, int p, int d) {
    FO[v] = ct;
    D[v] = d;
    ET[ct++] = v;
    for (auto x : adj[v]) {
        if (x != p) {
            dfs(x, v, d+1);
            ET[ct++] = v;
        }
    }
}

int lca(int v, int u) {
    if (v == u) {
        return v;
    }
    if (FO[v] > FO[u]) {
        swap(v, u);
    }

    int sz = 0;
    for (int i = 0; i <= 18; i++) {
        if ((1<<i) <= FO[u]-FO[v]) {
            sz = i;
        }
    }

    if (SPARSE[FO[v]][sz] <= SPARSE[FO[u]-(1<<sz)][sz]) {
        return SPARSE[FO[v]][sz];
    }
    return SPARSE[FO[u]-(1<<sz)][sz];
}

void solve() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[i].emplace_back(a);
        adj[a].emplace_back(i);
    }

    dfs(1, -1, 1); // dfs to construct euler tour and depth / first occurrence information needed for RMQ with sparse table

    for (int j = 0; (1<<j) <= 2*n-1; j++) {
        for (int i = 0; i+(1<<j)-1 < 2*n-1; i++) {
            if (!j) {
                SPARSE[i][j] = ET[i];
                continue;
            }
            if (D[SPARSE[i][j-1]] < D[SPARSE[i+(1<<(j-1))][j-1]]) {
                SPARSE[i][j] = SPARSE[i][j-1];
            }
            else {
                SPARSE[i][j] = SPARSE[i+(1<<(j-1))][j-1];
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b; cout << lca(a, b) << "\n";
    }
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
