#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 200001;

int n, q;
int input[MAXN], A[MAXN];
ll T[4*MAXN];
vector<int> adj[MAXN];
int inSubtree[MAXN]; // inclusive
int order[MAXN];
int ct = 0;

int dfs(int v, int p) {
    order[v] = ct++;
    A[order[v]] = input[v];
    inSubtree[v] = 1;
    for (auto x : adj[v]) {
        if (x != p) {
            inSubtree[v] += dfs(x, v);
        }
    }
    return inSubtree[v];
}

void build(int v, int repl, int repr, int (&A)[MAXN]) {
    if (repl == repr) {
        T[v] = A[repl];
        return;
    }
    int lc = v*2, rc = v*2+1;
    build(lc, repl, (repl+repr)/2, A);
    build(rc, (repl+repr)/2 + 1, repr, A);
    T[v] = T[lc]+T[rc];
}

void update(int v, int repl, int repr, int idx, ll val) {
    if (repl == repr) {
        T[v] = val;
        return;
    }
    int lc = v*2, rc = v*2+1;
    if (idx <= (repl+repr)/2) {
        update(lc, repl, (repl+repr)/2, idx, val);
    }
    else {
        update(rc, (repl+repr)/2 + 1, repr, idx, val);
    }
    T[v] = T[lc]+T[rc];
}

ll sum(int v, int repl, int repr, int l, int r) {
    if (l > r) return 0;
    if (repl == l && repr == r) {
        return T[v];
    }
    int lc = v*2, rc = v*2+1;
    return sum(lc, repl, (repl+repr)/2, l, min((repl+repr)/2, r)) +
    sum(rc, (repl+repr)/2 + 1, repr, max(l, (repl+repr)/2 + 1), r);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }    

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    dfs(1, -1);

    build(1, 0, n-1, A);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s; ll x; cin >> s >> x;
            update(1, 0, n-1, order[s], x);
        }
        else {
            int v; cin >> v;
            cout << sum(1, 0, n-1, order[v], order[v]+inSubtree[v]-1) << "\n";
        }
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
