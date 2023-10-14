#include <iostream>
#include <vector>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> xs(n, -1);
  vector<int64_t> hs(n, -1);
  for (int64_t i = 0; i < n; i++) {
      cin >> xs[i] >> hs[i];
  }

  // assume leftmost tree falls left
  int64_t maxL = 1, maxR = 0, ll, lr, rl, rr;
  for (int64_t i = 1; i < n - 1; i++) {
    ll = ((xs[i] - xs[i - 1]) > hs[i]) ? maxL + 1 : maxL;
    lr = ((xs[i + 1] - xs[i]) > hs[i]) ? maxL + 1 : maxL;
    rl = ((xs[i] - (xs[i - 1] + hs[i - 1])) > hs[i]) ? maxR + 1 : maxR;
    rr = ((xs[i + 1] - xs[i]) > hs[i]) ? maxR + 1 : maxR;

    maxL = max(ll, rl);
    maxR = max(lr, rr);
  }

  // assume rightmost tree falls right
  cout << ((n == 1) ? 1 : max(maxL, maxR) + 1) << endl;

  return 0;
}