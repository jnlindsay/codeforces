#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
  int64_t n, d;
  cin >> n >> d;

  // insert friends
  vector<tuple<int64_t, int64_t>> friends(n);
  for (int64_t i = 0; i < n; i++) {
    int64_t m, s;
    cin >> m >> s;
    friends[i] = make_tuple(m, s);
  }

  // sort friends
  sort(friends.begin(), friends.end(), [](const auto &a, const auto &b) {
    return get<0>(a) < get<0>(b);
  });

  // two pointers
  int64_t max = 0, j = 0, curr = 0;
  for (int64_t i = 0; i < n; i++) {

    if (i > 0) { curr -= get<1>(friends[i - 1]); }

    while (j < n && (get<0>(friends[j]) - get<0>(friends[i]) < d)) {
      curr += get<1>(friends[j]);
      j++;
    }

    max = (curr > max) ? curr : max;
  }

  cout << max << endl;

  return 0;
}