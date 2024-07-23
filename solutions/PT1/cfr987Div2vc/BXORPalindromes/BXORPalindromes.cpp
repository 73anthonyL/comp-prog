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

#define mp make_pair

int n; string s;
void solve() {
    cin >> n >> s;
    int changes = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            changes++;
        }
    }
    
    if (n%2) {
        // anything from changes up and below n-changes can work
        for (int i = 0; i <= n; i++) {
            if (i < changes || i > n-changes) {
                cout << '0';
                continue;
            }
            cout << '1';
        }
        cout << "\n";
    }
    else {
        // anything from changes up that includes
        for (int i = 0; i <= n; i++) {
            if (i < changes || i > n-changes) {
                cout << '0';
                continue;
            }

            cout << ((changes%2 == i%2) ? '1' : '0');
        }
        cout << "\n";
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
