#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int ct[26];

string s;
void solve() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ct[s[i]-'A']++;
    }

    int oddCount = 0, lastOdd = -1;
    for (int i = 0; i < 26; i++) {
        if (ct[i] % 2) {
            oddCount++;
            lastOdd = i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << "\n";
        return;
    }

    int lettersPlaced = 0;
    vector<char> ans(s.size()); 
    for (int i = 0; i < 26; i++) {
        if (ct[i] && !(ct[i]%2)) {
            for (int j = 0; j < ct[i]/2; j++) {
                ans[lettersPlaced+j] = ans[s.size()-lettersPlaced-1-j] = ('A'+i);
            }
            lettersPlaced += ct[i]/2;
        }
    }

    if (lastOdd != -1) {
        for (int i = 0; i < ct[lastOdd]; i++) {
            ans[lettersPlaced+i] = ('A'+lastOdd);
        }
    }

    for (char c : ans) {
        cout << c;
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    // cin >> t;
	while (t--) {
		solve();
	}
}
