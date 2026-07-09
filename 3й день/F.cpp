#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int max_n = 100;
  int max_s = 1000;

  vector<vector<int>> dp(max_n + 1, vector<int>(max_s + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= max_n; ++i) {
    for (int j = 0; j <= max_s; ++j) {
      for (int d = 0; d <= 9; ++d) {
        if (j >= d) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - d]) % MOD;
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;

    if (s > max_s) {
      cout << 0 << "\n";
    } else {
      cout << dp[n][s] << "\n";
    }
  }

  return 0;
}