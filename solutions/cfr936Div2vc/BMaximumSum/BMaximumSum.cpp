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
#define _GLIBCXX_DEBUG

const ll MOD = 1000000007;
int n, k;
void solve() {
    cin >> n >> k;
    
    ll currSum, maxSubarraySum;
    ll maxArrayElement = INT64_MIN, totSum = 0;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        totSum += a;
        maxArrayElement = max(maxArrayElement, a);
        if (!i) {
            currSum = maxSubarraySum = a;
            continue;
        }

        // choose to extend or include
        currSum = max(currSum+a, a);

        maxSubarraySum = max(maxSubarraySum, currSum);
    }
    
    if (maxArrayElement < 0) {
        cout << ((totSum % MOD + MOD)%MOD) << "\n";
        return;
    }
    
    totSum -= maxSubarraySum;
    for (int i = 0; i < k; i++) {
        maxSubarraySum *= 2;
        maxSubarraySum = (maxSubarraySum % MOD + MOD) % MOD;
    }
    
    cout << (((maxSubarraySum+totSum)%MOD + MOD) % MOD) << "\n";
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
