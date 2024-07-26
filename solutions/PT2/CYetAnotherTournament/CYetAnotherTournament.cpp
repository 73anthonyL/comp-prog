#define _GLIBCXX_DEBUG
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
using pii = pair<int, int>;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

bool comp(const pii &f, const pii &s) {
    if (f.second == s.second) {
        return f.first < s.first;
    }
    return f.second < s.second;
}

int n, m;
void solve() {
    cin >> n >> m;
    vector<pii> A;
    for (int i = 0; i < n; i++) {
        int z; cin >> z; A.emplace_back(z, i);
    }
    sort(A.begin(), A.end());
    
    int sum = 0, k = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i].first; 
        if (sum > m) {
            A[i].second++; 
        }
        else {
            k++;
        }
    }

    A.emplace_back(INT32_MAX, k);
    sort(A.begin(), A.end(), comp); 
    
	cin.tie(nullptr);
		
	int t = 1;
    cin >> t;
	while (t--) {
		solve();
	}
}
