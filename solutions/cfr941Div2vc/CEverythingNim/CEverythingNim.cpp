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
#define _GLIBCXX_DEBUG

int n, m;
void solve() {
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j]; 
        }
    }
    
    // can be opposite color: 4 quadrants
    vector<bool> black(4), white(4), canWhite(4), canBlack(4);
    for (int i = 0; i < m; i++) {
        if (g[0][i] == 'W') white[0] = true;
        if (g[n-1][i] == 'W') white[2] = true;
        if (g[0][i] == 'B') black[0] = true;
        if (g[n-1][i] == 'B') black[2] = true;
    }
    
    for (int i = 0; i < n; i++) {
        if (g[i][0] == 'W') white[3] = true;
        if (g[i][m-1] == 'W') white[1] = true;
        if (g[i][0] == 'B') black[3] = true;
        if (g[i][m-1] == 'B') black[1] = true;
    }

    if ((white[0] && white[1]) || g[0][m-1] == 'W') canWhite[0] = true;
    if ((black[0] && black[1]) || g[0][m-1] == 'B') canBlack[0] = true;
    if ((white[1] && white[2]) || g[n-1][m-1] == 'W') canWhite[3] = true;
    if ((black[1] && black[2]) || g[n-1][m-1] == 'B') canBlack[3] = true;
    if ((white[2] && white[3]) || g[n-1][0] == 'W') canWhite[2] = true;
    if ((black[2] && black[3]) || g[n-1][0] == 'B') canBlack[2] = true;
    if ((white[3] && white[0]) || g[0][0] == 'W') canWhite[1] = true;
    if ((black[3] && black[0]) || g[0][0] == 'B') canBlack[1] = true;

    if ((white[0] && white[2]) || (black[0] && black[2]) || (white[1] && white[3]) || (black[1] && black[3])) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}

// if the corners are not set up currently to undergo the full grid coloring, then
// you must flip one of the corners to a specific color this can be done with an "opposing diagonal rectangle"
// there are also only two corner pairs to check
