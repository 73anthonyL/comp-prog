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

ll a, b, c; 
void solve() {
    cin >> a >> b >> c;
    vector<ll> arr = {a, b, c};
    for (int i = 0; i < 5; i++) {
        sort(arr.begin(), arr.end());
        arr[0]++;
    }

    cout << arr[0] * arr[1] * arr[2] << "\n";
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
