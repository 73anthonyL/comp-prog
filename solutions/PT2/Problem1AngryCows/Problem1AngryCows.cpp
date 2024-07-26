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
#include <limits>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 50001;

int n;
int dpl[MAXN], dpr[MAXN];

void solve() {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; A[i];
    }
    sort(A.begin(), A.end());

    dpr[n-1] = 0, dpl[0] = 0;
    for (int i = 1; i < n; i++) {
        dpl[i] = max(A[i]-A[i-1], dpl[i-1]+1);
        dpr[n-i-1] = max(A[n-i]-A[n-i-1], dpr[n-i]+1);
    }
    
    double R = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // calculate how explody it would have to be to detonate both of these and all otherh haybales
            // max between the actual distance and power+1
            double radiusRequired = max(((double)A[j]-A[i])/2, (double)max(dpl[i], dpr[j])+1.0);
            R = min(R, radiusRequired);
        }
    }

    cout << fixed << setprecision(1) << R << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
