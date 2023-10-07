#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::string curr;
    std::cin >> curr;
    int len = curr.length();

    if (len <= 10) {
      std::cout << curr;
    } else {
      std::cout << curr[0] << len - 2 << curr[len - 1];
    }
    std::cout << std::endl;
  }
 
  return 0;
}