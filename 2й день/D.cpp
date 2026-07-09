#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const uint64_t MOD1 = 1e9 + 7;
const uint64_t MOD2 = 1e9 + 11;
const uint64_t P1 = 29;
const uint64_t P2 = 31;

struct StringHasher {
  vector<uint64_t> h1, h2;
  vector<uint64_t> pow1, pow2;

  StringHasher(const string& s) {
    int n = s.length();
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
      h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
      h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
      pow1[i + 1] = (pow1[i] * P1) % MOD1;
      pow2[i + 1] = (pow2[i] * P2) % MOD2;
    }
  }

  uint64_t get_substring_hash(int i, int len) const {
    uint64_t hash1 = (h1[i + len] + MOD1 - (h1[i] * pow1[len]) % MOD1) % MOD1;
    uint64_t hash2 = (h2[i + len] + MOD2 - (h2[i] * pow2[len]) % MOD2) % MOD2;
    return (hash1 << 32) | hash2;
  }
};

struct CustomHashSet {
  vector<uint64_t> table;
  vector<int> used_version;
  int cap;
  int current_version;

  CustomHashSet(int max_elements) {
    cap = 1;
    while (cap < max_elements * 2) cap *= 2;
    table.assign(cap, 0);
    used_version.assign(cap, 0);
    current_version = 0;
  }
  void clear() { current_version++; }

  bool insert(uint64_t val) {
    uint64_t h = val ^ (val >> 32);
    int idx = h & (cap - 1);

    while (used_version[idx] == current_version) {
      if (table[idx] == val) return false;
      idx = (idx + 1) & (cap - 1);
    }

    table[idx] = val;
    used_version[idx] = current_version;
    return true;
  }
};

long long get_total_distinct_substrings(const string& s) {
  int n = s.length();
  StringHasher hasher(s);

  long long total_distinct = 0;
  CustomHashSet hash_set(n);

  for (int len = 1; len <= n; len++) {
    hash_set.clear();
    for (int i = 0; i <= n - len; i++) {
      if (hash_set.insert(hasher.get_substring_hash(i, len))) {
        total_distinct++;
      }
    }
  }

  return total_distinct;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  if (cin >> s) {
    cout << get_total_distinct_substrings(s) << "\n";
  }

  return 0;
}