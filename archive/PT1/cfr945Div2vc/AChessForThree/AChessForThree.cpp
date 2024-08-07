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

int p1, p2, p3; 
void solve() {
    cin >> p1 >> p2 >> p3;

    if ((p1+p2+p3)%2) {
        cout << -1 << "\n";
        return;
    }

    vector<int> stage = {p1, p2, p3};
    
    bool works = true;
    int ans = 0;
    while (works) {
        if (stage[1] && stage[2]) {
            ans++;
            stage[1]--, stage[2]--;
            sort(stage.begin(), stage.end());
        }
        else {
            works = false;
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
