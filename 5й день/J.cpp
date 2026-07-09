#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = n; j >= i; --j) {
      dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }

  cout << dp[n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}