#include <iostream>
#include <vector>
using namespace std;

int find_res(
  int i,
  string input,
  vector<vector<int>>& prev
) {

  string res = "";
  int curr_i = i, curr_j = 0;
  while (true) {
    if (prev[curr_i][curr_j] == -1 || prev[curr_i][curr_j] != curr_j) {
      res = input[curr_i] + res;
    }

    if (prev[curr_i][curr_j] == -1) break;

    curr_j = prev[curr_i][curr_j];
    curr_i--;
  }

  cout << "YES\n" << res << endl;

  return 0;
}

int main() {
  vector<vector<bool>> dp(100, vector<bool>(8, false));
  vector<vector<int>> prev(100, vector<int>(8, -1));

  string input;
  cin >> input;

  int curr;
  for (int i = 0; i < input.size(); i++) {

    curr = input[i] - '0';

    if (curr == 0 || curr == 8) {
      cout << "YES\n" << curr << endl;
      return 0;
    };
    dp[i][curr % 8] = true;

    if (i > 0) {
      for (int j = 0; j < 8; j++) {
        if (dp[i - 1][j]) {
          dp[i][(j * 10 + curr) % 8] = true;
          prev[i][(j * 10 + curr) % 8] = j;

          dp[i][j] = true;
          prev[i][j] = j;

          if ((j * 10 + curr) % 8 == 0) {
            find_res(i, input, prev);
            return 0;
          }
        }
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}