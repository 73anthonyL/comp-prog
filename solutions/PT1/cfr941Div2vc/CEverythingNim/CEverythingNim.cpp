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

int n;
void solve() {
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; st.insert(a);
    }
    
    bool started = false;
    int last = -1;
    vector<int> delta;
    for (auto z : st) {
        if (!started) {
            delta.emplace_back(z);
            started = true;
            last = z;
            continue;
        }
        delta.emplace_back(z-last);
        last = z;
    }
    
    vector<bool> winner(delta.size()); // true if the starter is the winner, false if not
    winner[delta.size()-1] = true;

    for (int i = delta.size()-2; i >= 0; i--) {
        // do you want to end this turn or not?
        bool wantToEnd = !winner[i+1];
        if (!wantToEnd && delta[i] == 1) {
            winner[i] = false;
        }
        else {
            winner[i] = true;
        }
    }

    if (winner[0]) {
        cout << "Alice" << "\n";
    }
    else {
        cout << "Bob" << "\n";
    }

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
