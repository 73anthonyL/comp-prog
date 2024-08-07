#define _GLIBCXX_DEBUG
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using pil = pair<int, ll>;

#define dbg(v) cerr << #v << " = " << (v) << "\n";

#define mp make_pair

const int MAXN = 2501;
const ll INF = 5000000000000;

int n, m;
ll dist[MAXN];
vector<tuple<int, int, ll>> E;

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    E.emplace_back(a, b, -c);
  }

  for (int i = 2; i <= n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;
  bool changed;
  for (int i = 0; i < n; i++) {
    changed = false;
    for (int j = 0; j < m; j++) {
      if (dist[get<1>(E[j])] > dist[get<0>(E[j])] + get<2>(E[j])) {
        dist[get<1>(E[j])] = dist[get<0>(E[j])] + get<2>(E[j]);
        if (get<2>(E[j]) == n) {
          changed = true;
        }
      }
    }
    if (changed && i == n - 1) {
      cout << -1 << "\n";
      return;
    }
  }

  cout << -dist[n] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--) {
    solve();
  }
}
