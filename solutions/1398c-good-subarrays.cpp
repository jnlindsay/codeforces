#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
  const int ARRAY_MAX_SIZE = 100001;
  int64_t a[ARRAY_MAX_SIZE], p[ARRAY_MAX_SIZE];
  int64_t res = 0, t, n; // n < ARRAY_MAX_SIZE
  string input;
  cin >> t;

  p[0] = 0;
  for (int64_t i = 0; i < t; i++) {
    res = 0;

    // input
    cin >> n >> input;
    for (int64_t j = 0; j < n; j++) {
      a[j] = input[j] - '0';
      p[j + 1] = p[j] + a[j];
    }

    // calculate p_i - i and sort
    for (int64_t j = 0; j <= n; j++) { p[j] = p[j] - j; }
    sort(p, p + n + 1);

    // find copies
    int64_t curr = p[0], window_len = 1;
    for (int64_t j = 1; j <= n; j++) {
      if (p[j] == curr) { window_len++; }
      if (p[j] != curr || j == n) {
        res += (window_len * (window_len - 1)) / 2;
        window_len = 1;
      }
      curr = p[j];
    }

    cout << res << endl;
  }

  return 0;
}