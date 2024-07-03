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

int n;
void solve() {
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll moves = 0;
    for (int i = (n+1)/2; i <= n; i++) {
        if (i == ((n+1)/2)) {
            arr[i]++;
            continue;
        }
        if (arr[i] < arr[i-1]) {
            moves += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << moves+1 << "\n";
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

