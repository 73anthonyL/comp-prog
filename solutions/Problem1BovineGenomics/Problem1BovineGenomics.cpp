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
#define _GLIBCXX_DEBUG

int n, m;
int p = 31, MOD = 1e9+9;
void solve() {
    cin >> n >> m;
    vector<vector<ll>> S(n, vector<ll> (m)), P(n, vector<ll> (m));
    vector<vector<char>> spotty(n, vector<char> (m)), plain(n, vector<char> (m));
    vector<ll> pwr = {1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotty[i][j];
            if (j && !i) {
                pwr.emplace_back((pwr[j-1]*p)%MOD);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!j) {
                S[i][j] = spotty[i][j]-'A'+1;
                P[i][j] = plain[i][j]-'A'+1;
                continue;
            }

            S[i][j] = S[i][j-1]+(pwr[m-j-1]*(spotty[i][j]-'A'+1));
            S[i][j] %= MOD;
            P[i][j] = P[i][j-1]+(pwr[m-j-1]*(plain[i][j]-'A'+1));
            P[i][j] %= MOD;
        }
    }
    
    int lo = 1, hi = m;
    while (lo < hi) {
        int len = lo + (hi-lo)/2;
        // go through all intervals size len
        int ct = 0;
        for (int i = 0; i < m-len+1; i++) {
            bool found = false;
            unordered_set<ll> lookup;
            for (int j = 0; j < n; j++) {
                if (!i) {
                    lookup.insert(S[j][i+len-1]);
                    continue;
                }
                lookup.insert((((S[j][i+len-1]-S[j][i-1]+MOD)%MOD)*pwr[i])%MOD);
            }
            
            for (int j = 0; j < n; j++) {
                if (!i) {
                    if (lookup.find(P[j][i+len-1]) != lookup.end()) {
                        found = true;
                    }
                    continue;
                }
                ll check = (((P[j][i+len-1]-P[j][i-1]+MOD)%MOD)*pwr[i])%MOD;
                if (lookup.find(check) != lookup.end()) {
                    
                    found = true;
                }
            }
            if (found) ct++;
        }
        
        if (ct != m-len+1) {
            hi = len;
        }
        else {
            lo = len+1;
        }
    }

    cout << lo << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}
}
