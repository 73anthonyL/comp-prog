#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <math.h>
#include <numeric>
#include <set>
#include <cstdint>
#include <string>
#include <map>
#include <bitset>
using namespace std;
using ll = long long;
#define dbg(v) \
    cout << #v << " = " << (v) << "\n"; 

string a, b;
void solve() {
    cin >> a >> b;
    int ans = INT32_MAX;

    for (int i = 0; i < b.size(); i++) {
        // fix the beginning of b, use dynamic point j on a
        int l = i; int r = 0;
        int currCommon = 0;
        while (l < b.size() && r < a.size()) {
            if (b[l] == a[r]) {
                l++; r++;
                currCommon++;
            }
            else {
                r++;
            }
        }
        ans = min(ans, (int)a.size()+(int)b.size()-currCommon);
    }

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
