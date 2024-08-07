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

#define mp make_pair

int n, s, m;

void solve() {
    cin >> n >> s >> m;
    vector<pii> E;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; E.emplace_back(l, r);
    }
    sort(E.begin(), E.end());    

    if (E[0].first-0 >= s || m-E.rbegin()->second >= s) {
        cout << "YES" << "\n";
        return;
    }
    
    for (int i = 0; i < E.size()-1; i++) {
        if (E[i+1].first-E[i].second >= s) {
            cout << "YES" << "\n";
            return;
        }
    }
    
    cout << "NO" << "\n";
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
