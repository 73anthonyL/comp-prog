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

int n, k;
void solve() {
    cin >> n >> k;
    int countOnes = 0;
    vector<ll> arr;
    for (int i = 0; i < k; i++) {
        ll a; cin >> a; 
        if (a == 1) {
            countOnes++;
            continue;
        }
        arr.emplace_back(a);
    }
    
    ll ans = 0;
    if (countOnes == k-1) {
        cout << countOnes << "\n";
        return;
    }

    if (countOnes == k) {
        cout << countOnes-1 << "\n";
        return;
    }

    ans += countOnes;
    sort(arr.begin(), arr.end());
    

    for (int i = 0; i < arr.size()-1; i++) {
        ans += (arr[i]-1); 
        ans += arr[i];
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
