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

int n; string s;
void solve() {
    cin >> n >> s;
    bool aWin = false, bWin = false;
    for (int X = 1; X <= n; X++) {
        for (int Y = 1; Y <= n; Y++) {
            if (X*Y > n) continue;
            int totAWins = 0, totBWins = 0;
            int apWins = 0, bpWins = 0;
            bool aWonCurrent = true;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'A') {
                    apWins++;
                }
                else {
                    bpWins++;
                }
                // check if any of them have score equal to X
                if (apWins == X) {
                    totAWins++;
                    aWonCurrent = true;
                    apWins = bpWins = 0;
                }
                else if (bpWins == X) {
                    totBWins++;
                    aWonCurrent = false;
                    bpWins = apWins = 0;
                }
            }

            if (bpWins == 0 && apWins == 0) {
                if (totAWins == Y && aWonCurrent) {
                    aWin = true;
                    dbg("aWin"); dbg(X); dbg(Y);
                }
                else if (totBWins == Y && !aWonCurrent) {
                    bWin = true;
                    dbg("bWin"); dbg(X); dbg(Y);
                }
            }
        }
    }

    if (aWin && bWin) cout << "?\n";
    else if (aWin) cout << "A\n";
    else if (bWin) cout << "B\n";

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
