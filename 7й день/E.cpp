#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int k, int n, const string& s) {
  vector<int> flipped(n, 0);
  int flip_count = 0;

  for (int i = 0; i < n; ++i) {
    if (i >= k) {
      flip_count ^= flipped[i - k];
    }

    int current_val = (s[i] - '0') ^ flip_count;

    if (current_val == 0) {
      if (i + k > n) {
        return false;
      }
      flipped[i] = 1;
      flip_count ^= 1;
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int k = n; k >= 1; --k) {
    if (check(k, n, s)) {
      cout << k << "\n";
      return;
    }
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