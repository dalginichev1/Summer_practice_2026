#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 676767677;

void solve() {
  int n, m;
  if (!(cin >> n >> m)) return;

  vector<int> b(n);
  vector<long long> cnt(m, 0);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    cnt[b[i]]++;
  }

  vector<long long> C(m + 1, 0);
  for (int i = 0; i < m; ++i) {
    C[i + 1] = C[i] + cnt[i];
  }

  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 0) continue;

    int t = b[i];
    int min_neighbor = m + 1;
    if (i > 0) min_neighbor = min(min_neighbor, b[i - 1]);
    if (i < n - 1) min_neighbor = min(min_neighbor, b[i + 1]);

    if (min_neighbor >= t) {
      cout << 0 << "\n";
      return;
    } else if (min_neighbor == t - 1) {
      ans = (ans * C[t]) % MOD;
    } else {
      ans = (ans * cnt[t - 1]) % MOD;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}