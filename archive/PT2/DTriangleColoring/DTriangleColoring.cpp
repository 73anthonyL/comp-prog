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

const ll MOD = 998244353;

ll factorial(ll n) {
    ll ret = n;
    for (ll i = n-1; i >= 1; i--) {
        ret *= i; 
        ret %= MOD;
    }
    return ret;
}

// Function to calculate modular multiplicative inverse using extended Euclidean algorithm
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to calculate (a / b) % m
ll modDivide(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);
    assert(inv >= 0);
    return (inv * a) % m;
}

ll nCr(ll n, ll k) {
    return modDivide(factorial(n), (factorial(n-k)*factorial(k))%MOD, MOD);
}

int n;
void solve() {
    cin >> n;
    ll ans = nCr(n/3, n/6);
    for (int i = 0; i < n/3; i++) {
        map<ll, int> M;
        ll currmin = INT64_MAX;
        for (int j = 0; j < 3; j++) {
            ll a; cin >> a; M[a]++;
            currmin = min(currmin, a);
        }
        ans *= M[currmin];
        cerr << M[currmin] << "\n";
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
	while (t--) {
		solve();
	}
}
