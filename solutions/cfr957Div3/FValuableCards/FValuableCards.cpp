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

ll n, x;
void solve() {
    cin >> n >> x;
    deque<ll> dq;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a; dq.push_back(a);
    }

    // alternate from the left and right
    int ans = 1;
    bool left = true;
    set<ll> prods;
    prods.insert(1);
    while (!dq.empty()) {
        if (left) {
            if (dq.front() > x/2) {
                dq.pop_front(); 
            }
            else {
                vector<ll> curr;
                bool flag = false;
                for (auto x : prods) {
                    if (x*dq.front() == x) {
                        dbg(x*dq.front()); dbg(x); dbg("ans1");
                        ans++;
                        left = false;
                        prods.clear();
                        prods.insert(1);
                        flag = true;
                        break;
                    }
                    curr.emplace_back(x*dq.front());
                }
                if (!flag) {
                    for (auto x : curr) {
                        prods.insert(x);
                    }
                    dq.pop_front();
                }
            }
        }
        else {
            if (dq.back() > x/2) {
                dq.pop_back(); 
            }
            else {
                vector<ll> curr;
                bool flag = false;
                for (auto x : prods) {
                    if (x*dq.back() == x) {
                        dbg(x*dq.back()); dbg(x); dbg("ans2");
                        ans++;
                        left = true;
                        prods.clear();
                        prods.insert(1);
                        flag = true;
                        break;
                    }
                    curr.emplace_back(x*dq.back());
                }
                if (!flag) {
                    for (auto x : curr) {
                        prods.insert(x);
                    }
                    dq.pop_back();
                }
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
        dbg(t);
		solve();
	}
}
