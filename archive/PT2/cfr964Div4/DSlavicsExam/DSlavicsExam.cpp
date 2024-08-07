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

#define mp make_pair

string S, T;
void solve() {
    cin >> S >> T;
    queue<char> q;
    for (auto x : T) {
        q.push(x); 
    }
    
    int pt = 0;
    int cnt = 0;
    while (!q.empty()) {
        if (S[pt] == q.front() || S[pt] == '?') {
            S[pt++] = q.front();
            cnt++;
        }
        q.pop();
    }
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            S[i] = 'a';
        }
    }

    if (cnt == T.size()) {
        cout << "YES" << "\n";
        cout << S << "\n";
        return;
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
