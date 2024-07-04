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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int lo = 1, hi = n;
    // first true
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        vector<int> cnt(21);
        
        int currOr = 0, masterOr = 0;
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j <= 20; j++) {
                if ((1<<j)&arr[i]) {
                    cnt[j]++;
                    if (cnt[j] == 1) {
                        currOr |= (1<<j);
                    }
                }
            }
        }
        
        masterOr = currOr;
        bool works = true;
        for (int i = 1; i < n-mid+1; i++) {
            for (int j = 0; j <= 20; j++) {
                // remove the previous
                if ((1<<j)&arr[i-1]) {
                    cnt[j]--;
                    if (!cnt[j]) {
                        currOr ^= (1<<j);
                    }
                }
                // add new
                if ((1<<j)&arr[i+mid-1]) {
                    cnt[j]++;
                    if (cnt[j] == 1) {
                        currOr |= (1<<j);
                    }
                }
            }
            if (currOr != masterOr) {
                works = false;
            }
        }

        if (works) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }   
    
    cout << lo << "\n";
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
