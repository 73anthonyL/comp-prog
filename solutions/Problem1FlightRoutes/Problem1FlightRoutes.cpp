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

const int MAXN = 751;

int n;
bool P[MAXN][MAXN];
bool df[MAXN][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            P[i][i+j+1] = (s[j] == '0') ? 0 : 1;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j <= n-i; j++) {
            if (i == 1) {
                df[j][j+1] = P[j][j+1];
                if (df[j][j+1]) ans++;
                continue;
            }
            int parity = 0;
            for (int mid = j+1; mid < j+i; mid++) {
                if (df[mid][j+i]) {
                    parity += P[j][mid];
                    parity %= 2;
                }
            }

            if (parity != P[j][j+i]) {
                df[j][j+i] = 1;
                ans++;
            }
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
