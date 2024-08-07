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
    cout << #v << " = " << (v) << ", ";
    
int n, k;
void solve() {
    cin >> n >> k;
    
    if (k > (4*n)-4) {
        cout << k-((4*n)-4) + ((4*n)-4)/2 << "\n";
    }
    else {
        cout << (k+1)/2 << "\n";
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
