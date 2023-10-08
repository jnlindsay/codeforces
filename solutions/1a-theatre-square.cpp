#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int64_t n, m, a;
  cin >> n >> m >> a;

  int nRound = (n % a == 0) ? 0 : 1;
  int mRound = (m % a == 0) ? 0 : 1;

  cout << (n / a + nRound) * (m / a + mRound) << endl;

  return 0;
}
