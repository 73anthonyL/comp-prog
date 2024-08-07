#define _GLIBCXX_DEBUG
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

int a, b, c, d;
int win(int a, int b, int c, int d) {
    if ((a > c && b >= d) || b > d && a >= c) {
        return 1;
    }
    return 0;
}

void solve() {
    cin >> a >> b >> c >> d;
    int ans = 0;
    ans += win(a, b, c, d);
    swap(c, d);
    ans += win(a, b, c, d);
    swap(a, b);
    ans += win(a, b, c, d);
    swap(c, d);
    ans += win(a, b, c, d);
    cout << ans << "\n";
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
