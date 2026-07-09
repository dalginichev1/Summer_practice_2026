#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> c(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j];
    }
  }

  int num_states = 1 << n;

  vector<vector<int>> dp(num_states, vector<int>(n, INF));

  dp[1][0] = 0;

  for (int mask = 1; mask < num_states; ++mask) {
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (!(mask & (1 << v))) {
          int next_mask = mask | (1 << v);
          if (dp[mask][u] + c[u][v] < dp[next_mask][v]) {
            dp[next_mask][v] = dp[mask][u] + c[u][v];
          }
        }
      }
    }
  }

  int ans = INF;
  int full_mask = num_states - 1;

  for (int u = 0; u < n; ++u) {
    if (dp[full_mask][u] != INF) {
      ans = min(ans, dp[full_mask][u] + c[u][0]);
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}