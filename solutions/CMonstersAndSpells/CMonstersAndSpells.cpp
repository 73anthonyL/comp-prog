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
using pib = pair<int, bool>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
#define _GLIBCXX_DEBUG

int n;
void solve() {
    cin >> n;
    vector<int> appears(n), health(n);
    for (int i = 0; i < n; i++) {
        cin >> appears[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    
    vector<pib> events; // true symbolizes end event, false symbolizes start event
    for (int i = 0; i < n; i++) {
        events.emplace_back(make_pair(appears[i], true)); 
        events.emplace_back(make_pair(appears[i]-health[i]+1, false));
    }
    sort(events.begin(), events.end());

    ll ans = 0;
    int active = 0; int timeStarted = 0;
    for (int i = 0; i < events.size(); i++) {
        if (events[i].second) {
            active--;
            if (!active) {
                ans += (((ll)(events[i].first-timeStarted+1)*(ll)(events[i].first-timeStarted+2))/(ll)2);
                //dbg(events[i].first); dbg(timeStarted);
            }
        }
        else {
            active++;
            if (active == 1) {
                timeStarted = events[i].first;
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
