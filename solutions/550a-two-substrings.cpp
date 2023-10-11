#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool ab = false;
  bool ba = false;
  bool triple = false;

  int64_t i = 0;
  while (i < s.length() - 1) {
    if (s[i] == 'A' && s[i + 1] == 'B') {
      if (s[i + 2] == 'A' && !triple) {
        triple = true;
        i += 3;
      } else {
        ab = true;
        i += 2;
      }
    } else if (s[i] == 'B' && s[i + 1] == 'A') { 
      if (s[i + 2] == 'B' && !triple) {
        triple = true;
        i += 3;
      } else {
        ba = true;
        i += 2;
      }
    } else {
      i++;
    }

    if ((ab && ba) || (triple && ab) || (triple && ba)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}