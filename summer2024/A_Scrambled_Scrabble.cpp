#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

string s;
void solve() {
    cin >> s; 
    int consonantCount = 0, vowelCount = 0, nCount = 0, gCount = 0, yCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            nCount++;
        }
        else if (s[i] == 'G') {
            gCount++;
        }
        else if (s[i] == 'Y') {
            yCount++;
        }
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            vowelCount++;
        }
        else {
            consonantCount++;
        }
    }

    if (nCount > gCount) {
        consonantCount += (nCount-gCount);
        nCount = gCount;
    }
    else {
        consonantCount += (gCount-nCount);
        gCount = nCount;
    }

    int ans = 0;
    for (int ngPairs = 0; ngPairs <= nCount; ngPairs++) {
        for (int yVowels = 0; yVowels <= yCount; yVowels++) {
            int wordsMade = min(vowelCount+yVowels, (consonantCount + (yCount-yVowels) + ngPairs + (2*(nCount-ngPairs)))/2);
            ans = max(ans, (wordsMade*3)+(min(ngPairs, wordsMade*2)));
        }
    }

    cout << ans << "\n";
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
