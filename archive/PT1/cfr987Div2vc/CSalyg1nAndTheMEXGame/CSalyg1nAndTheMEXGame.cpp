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
#include <cassert>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
void solve() {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }
    
    int MEX = 0, pt = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            MEX = n;
            continue;
        }
        if (i != A[pt]) {
            MEX = i;
            break;
        }
        pt++;
    }
    
    cout << MEX << "\n";
    int y; cin >> y;
    while (y != -1) {
        cout << y << "\n";
        cin >> y;
    }

}

int main() {
	ios::sync_with_stdio(false);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
