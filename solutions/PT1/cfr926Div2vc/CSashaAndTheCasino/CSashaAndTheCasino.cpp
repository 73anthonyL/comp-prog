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
    
ll k, x, a;
void solve() {
    cin >> k >> x >> a;

    // sasha loses x times in a row initially:
    a -= x;
    if (a <= 0) {
        cout << "NO" << "\n";
        return;
    }

    // if she has successfully survived, now you must evaluate how much she wins right now by betting all her money
    ll betAll = (a-1)*(k-1);
    
    dbg(betAll);
    if (betAll < x) {
        cout << "NO" << "\n";
        return;
    }
    
    // if it is always uncertain, she must bet 1 coin only for everything, or else she loses more than she needs to

    dbg(x); dbg(k);
    if (x >= k) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
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
