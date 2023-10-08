#include <iostream>
using namespace std;

int main() {
  int n;
  int latestEven = -1;
  int latestOdd = -1;
  int evenState = 0; // 0 = NONE, 1 = ONE, 2 = AT LEAST TWO
  int oddState  = 0;

  cin >> n;

  int curr;
  for (int i = 1; i <= n; i++) {
    cin >> curr;

    // update context
    bool currEven = (curr % 2 == 0);
    if (currEven) {
      if (evenState < 2) { evenState++; }
      latestEven = i;
    } else {
      if (oddState < 2) { oddState++; }
      latestOdd = i;
    }

    // react to context
    if (evenState == 2 && latestOdd != -1) {
      cout << latestOdd << endl;
      return 0;
    }
    if (oddState == 2 && latestEven != -1) {
      cout << latestEven << endl;
      return 0;
    }
  }

  return 0;
}