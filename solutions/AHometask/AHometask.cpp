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
    
string s;
int k;
void solve() {
    cin >> s;
    cin >> k; 
    
    vector<int> m(26);

    int ct = 1;
    for (int i = 0; i < k; i++) {
        char a, b; cin >> a >> b;
        m[a-'a'] = ct;
        m[b-'a'] = ct;
        ct++;
    }
    
    int last = m[s[0]];
    int len = 1;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (m[s[i]] != last) {
            // reset len and account for how many must be deleted
            ans += (len/2);
            len = 1;
        }
        else {
            len++;
        }
        last = m[s[i]];
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

/*
 * split the string into segments where the segments have all the characters belong to the same class of strings
 * for each class of strings, if they are even, you delete len/2. if they are odd, you delete len/2 as well
 */
