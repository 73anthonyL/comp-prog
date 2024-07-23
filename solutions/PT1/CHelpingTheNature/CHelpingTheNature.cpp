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
    ll firstItem = 0, last = 0, totSum = 0, lsum = 0;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        if (!i) {
            firstItem = a;
            last = a;
            continue;
        }
        
        ll diff = a-last;
        totSum += abs(diff); 
        if (diff < 0) {
            lsum += diff;
        }
        last = a;
    }
    
    totSum += abs(firstItem+lsum);

    cout << totSum << "\n";
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
