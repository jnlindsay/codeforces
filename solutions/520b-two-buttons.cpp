#include <iostream>
using namespace std;

int main() {
  int64_t target, start;
  cin >> target >> start;

  int64_t res = 0;
  while (start > target) {
    start = (start % 2 == 0) ? (start / 2) : start + 1;
    res++;
  }

  cout << res + target - start << endl;
  return 0;
}