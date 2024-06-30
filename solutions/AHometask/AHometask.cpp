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
using pcc = pair<char, char>;
#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";
    
string s;
int k;
void solve() {
    cin >> s;
    cin >> k; 
    
    map<char, int> m;
    vector<pcc> grp(14);
    int ct = 1;
    for (int i = 0; i < k; i++) {
        char a, b; cin >> a >> b;
        m[a] = ct;
        m[b] = ct;
        if (a > b) swap(a, b);
        grp[ct] = make_pair(a, b);
        ct++;
    }
    
    int ans = 0;
    int lastid = m[s[0]];
    int fct = 0, sct = 0;
    for (int i = 1; i < s.size(); i++) {
        if (m[s[i]] != lastid)  {
            ans += min(fct, sct); 
            fct = 0, sct = 0;
        }
        else {
            if (lastid) {
                
            }
        }
        lastid = m[s[i]];
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

// go through all segments
