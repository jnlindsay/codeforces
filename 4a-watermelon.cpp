#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n == 2 || n % 2 != 0) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }

  return 0;
}