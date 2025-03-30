#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 21;
char G[MAXN][MAXN];
int vis[MAXN][MAXN];
int ct = 0;
unordered_set<char> distinctColors;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int tlr, tlc, brr, brc;

bool ok(int r, int c) {
    return r >= tlr && r <= brr && c >= tlc && c <= brc;
}

bool failedColorTest = false;
void ff(int r, int c) {
    if (vis[r][c] == ct) return;
    if (distinctColors.size() == 2) {
        failedColorTest = true;
        return;
    }

    vis[r][c] = ct;
    distinctColors.insert(G[r][c]);
    for (int i = 0; i < 4; i++) {
        if (ok(r+dr[i], c+dc[i])) {
            ff(r+dr[i], c+dc[i]);
        }
    }
}

int n;

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
        }
    }

    for (int r1 = 1; r1 <= n; r1++) {
        for (int r2 = r1+1; r2 <= n; r2++) {
            for (int c1 = 1; c1 <= n; c1++) {
                for (int c2 = c1+1; c2 <= n; c2++) {
                    distinctColors.clear();
                    ct++;
                    tlr = r1, tlc = c1, brr = r2, brc = c2;
                    failedColorTest = false;
                    for (int r = r1; r <= r2; r++) {
                        for (int c = c1; c <= c2; c++) {
                            if (vis[r][c] != ct) {
                                ff(tlr, tlc);
                                if (failedColorTest) {
                                    break;
                                }
                            }
                        }
                        if (failedColorTest) {
                            break;
                        }
                    }
                    if (failedColorTest) continue;
                    
                }
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
    // freopen("where.in", stdin);
    // freopen("where.out", stdout);

	int t = 1;
    // cin >> t;
	while (t--) {
		solve();
	}
}
