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
    cerr << #v << " = " << (v) << "\n";

int n;
void solve() {
    cin >> n;
    vector<vector<int>> sts, idxs(51);
    vector<int> cnt(51);
    
    int sz = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        vector<int> curr;
        for (int j = 0; j < k; j++) {
            int a; cin >> a; curr.emplace_back(a);
            idxs[a].emplace_back(i);
            cnt[a]++;
            if (cnt[a] == 1) {
                sz++;
            }
        }
        sts.emplace_back(curr);
    }
   
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        if (!cnt[i]) continue;
        for (auto z : idxs[i]) {
            for (auto x : sts[z]) {
                cnt[x]--;
                if (!cnt[x]) sz--;
            }
        }
        ans = max(ans, sz);
        for (auto z : idxs[i]) {
            for (auto x : sts[z]) {
                cnt[x]++;
                if (cnt[x] == 1) sz++;
            }
        }

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
