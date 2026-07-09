#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;

  string river = "L" + s + "L";

  vector<int> dp(n + 2, INF);
  dp[0] = 0;

  for (int i = 0; i <= n; ++i) {
    if (dp[i] == INF) continue;

    if (river[i] == 'L') {
      for (int jump = 1; jump <= m && i + jump <= n + 1; ++jump) {
        int next = i + jump;
        if (river[next] != 'C') {
          dp[next] = min(dp[next], dp[i]);
        }
      }
    } else if (river[i] == 'W') {
      int next = i + 1;
      if (next <= n + 1 && river[next] != 'C') {
        dp[next] = min(dp[next], dp[i] + 1);
      }
    }
  }

  if (dp[n + 1] <= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}