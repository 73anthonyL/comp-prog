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

#define mp make_pair

struct SubarraySum {
    int s, e;
    ll val;
    SubarraySum(int s, int e, ll val) {
        this->s = s;
        this->e = e;
        this->val = val;
    }

    bool contains(int idx) {
        return idx <= e && idx >= s;
    }
};

bool comp(const SubarraySum &l, const SubarraySum &r) {
    return l.val < r.val; 
}

int n;
void solve() {
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<SubarraySum> S;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j]; 
            S.emplace_back(i, j, sum);
        }
    }
    sort(S.begin(), S.end(), comp);

    for (int i = 0; i < n; i++) {
        ll minDiff = INT64_MAX;
        for (int j = 0; j < S.size()-1; j++) {
            if (S[j].contains(i) != S[j+1].contains(i)) {
                minDiff = min(minDiff, abs(S[j].val-S[j+1].val));
            }
        }
        cout << minDiff << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
