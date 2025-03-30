#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define dbg(v) \
    cerr << #v << " = " << (v) << "\n";

#define mp make_pair

int n;
void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
    }
    else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << "\n";
    }
    else if (n == 4) {
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << "\n";
    }
    else {
        for (int i = n; i > 0; i-=2) {
            cout << i << " ";
        }
        for (int i = n-1; i > 0; i-=2) {
            if (i == 1 || i == 2) {
                cout << i << "\n";
            }
            else {
                cout << i << " ";
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t = 1;
    //cin >> t;
	while (t--) {
		solve();
	}
}
