#include <iostream>
using namespace std;

const int64_t modulant = 1e9 + 7;
const int64_t zero = 0;
int64_t dp[100][2] = {{0}};

void add_mod(int64_t &a, int64_t b) {
  a += b;
  if (a >= modulant) { a -= modulant; }
}

int main() {
  int64_t n, k, d;
  cin >> n >> k >> d;

  dp[0][0] = 1;
  dp[0][1] = 0;

  for (int64_t i = 1; i <= n; i++) {
    for (int64_t j = max(zero, i - k); j <= i - 1; j++) {
      if (j <= i - d) { // containing segments >= d
        add_mod(dp[i][1], dp[j][0]);
        add_mod(dp[i][1], dp[j][1]);
      } else {          // all segments < d
        add_mod(dp[i][0], dp[j][0]);
        add_mod(dp[i][1], dp[j][1]);
      }
    }
  }

  cout << dp[n][1] << endl;

  return 0;
}