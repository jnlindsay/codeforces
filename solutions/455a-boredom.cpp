#include <iostream>
#include <map>
using namespace std;

map<int64_t, int64_t> hashMap; // must be ordered

int main() {
  int64_t n;
  cin >> n;

  // configure hash map
  for (int64_t i = 0; i < n; i++) {
    int64_t curr;
    cin >> curr;
    if (hashMap.find(curr) == hashMap.end()) {
      hashMap[curr] = 1;
    } else {
      hashMap[curr]++;
    }
  }

  // iterate through hash map
  int64_t window1 = 0, window2 = -1, window3 = -1;
  int64_t window1Key = 0, window2Key = -1;
  bool window2Set = false;
  for (const auto& pair : hashMap) {
    if (!window2Set) { // set second element of window
      window2 = pair.first * pair.second;
      window2Key = pair.first;
      window2Set = true;
      continue;
    }

    // calculate window3
    int64_t currPoints = pair.first * pair.second;
    if (window1Key == window2Key - 1) {
      if (window2Key == pair.first - 1) {
        window3 = max(window2, window1 + currPoints);
      } else {
        window3 = max(window1, window2) + currPoints;
      }
    } else {
      if (window2Key == pair.first - 1) {
        window3 = max(window2, window1 + currPoints);
      } else {
        window3 = window2 + currPoints;
      }
    }

    // move window
    window1 = window2;
    window2 = window3;
    window1Key = window2Key;
    window2Key = pair.first;
  }

  if (window3 == -1) { // at most 2 key-value pairs
    if (window1Key == window2Key - 1) {
      cout << max(window1, window2) << endl;
    } else {
      cout << window1 + window2 << endl;
    }
  } else {
    cout << window3 << endl;
  }

  return 0;
}
