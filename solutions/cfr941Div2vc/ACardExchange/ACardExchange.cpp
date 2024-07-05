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

int n, k;
void solve() {
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; m[a]++;
    }
    
    bool kOrAbove = false;
    for (auto [_, v] : m) {
        if (v >= k) {
            kOrAbove = true;
        }
    }

    cout << ((kOrAbove) ? k-1 : n) << "\n";
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
