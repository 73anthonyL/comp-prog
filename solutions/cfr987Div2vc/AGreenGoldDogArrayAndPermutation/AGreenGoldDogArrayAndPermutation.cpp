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
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG

#define mp make_pair

int n;
void solve() {
    cin >> n;
    
    vector<pii> A;
    for (int i = 0; i < n; i++) {
        int z; cin >> z;
        A.emplace_back(z, i);
    }
    sort(A.begin(), A.end());

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[A[i].second] = n-i;     
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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
