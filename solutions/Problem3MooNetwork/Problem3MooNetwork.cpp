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

int n;
unordered_map<ll, vector<ll>> yLevel;
set<int> distinctLevels;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        yLevel[b].emplace_back(a);
        distinctLevels.insert(b);
    }
    
    ll ans = 0;
    for (auto &[k, v] : yLevel) {
        sort(v.begin(), v.end());
        bool first = true;
        ll last = 0;
        for (auto x : v) {
            if (first) {
                first = false;
                last = x;
                continue;
            }
            ans += (x-last);
            last = x;
        }
    }
    
    dbg(ans);
    if (yLevel.size() == 1) {
        cout << ans << "\n";
        return;
    }

    vector<int> lvls(distinctLevels.begin(), distinctLevels.end());
    for (int i = 0; i < lvls.size()-1; i++) {
        int lvl1 = lvls[i], lvl2 = lvls[i+1];
        int l = 0, r = 0; ll minDiff = INT64_MAX, lvldist = lvl2-lvl1;
        while (l < yLevel[lvl1].size() && r < yLevel[lvl2].size()) {
            minDiff = min(minDiff, abs(yLevel[lvl1][l]-yLevel[lvl2][r]));
            if (yLevel[lvl1][l] <= yLevel[lvl2][r]) {
                l++;
            }
            else {
                r++;
            }
        }
        dbg(lvl1); dbg(lvl2); dbg(minDiff*minDiff); dbg(lvldist*lvldist);
        ans += (minDiff*minDiff)+(lvldist*lvldist);
    }

    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
