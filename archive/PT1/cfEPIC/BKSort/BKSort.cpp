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
#define int ll
#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
    
int n;
void solve() {
    cin >> n;
    vector<int> arr(n), makeND(n); int msf = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        if (i == 0) {
            makeND[i] = 0;
            msf = arr[i];
            continue;
        }
        
        makeND[i] = ((msf > arr[i]) ? msf-arr[i] : 0);
        msf = max(msf, arr[i]);
    }
    
    int ans = 0;
    priority_queue<int> balancer;
    for (int i = 0; i < n; i++) {
        if (makeND[i] > 0) {
            balancer.push(-makeND[i]);
        }
    }

    int subsofar = 0;
    while (!balancer.empty()) {
        ans += (balancer.size()+1)*(-balancer.top()-subsofar);
        subsofar += (-balancer.top()-subsofar);
        balancer.pop();
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
