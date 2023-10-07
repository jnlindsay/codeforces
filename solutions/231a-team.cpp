#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int total = 0;

  for (int i = 0; i < n; i++) {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    if (num1 + num2 + num3 >= 2) {
      total += 1;
    }
  }

  cout << total;

  return 0;
}