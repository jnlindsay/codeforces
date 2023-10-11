#include <iostream>
#include <vector>
using namespace std;

int64_t dfs(
  int64_t curr, 
  int64_t prev,
  int64_t m,
  vector<vector<int64_t>>& nodes, 
  vector<bool>& cats,
  int64_t numCats
) {
  // check consecutive cats
  int64_t newNumCats = numCats;
  if (cats[curr - 1]) { newNumCats++; }
  else { newNumCats = 0; }
  if (newNumCats > m) { return 0; }

  // leaf node reached
  if (curr != 1 && nodes[curr - 1].size() == 1) {
    return 1;
  }

  int numRestaurants = 0;
  for (const auto& next : nodes[curr - 1]) {
    if (next == prev) { continue; }
    numRestaurants += dfs(next, curr, m, nodes, cats, newNumCats);
  }

  return numRestaurants;
}

int main() {
  int64_t n, m;
  cin >> n >> m;

  // unordered_map<int64_t, vector<int64_t>> hashMap;
  vector<vector<int64_t>> nodes(n);
  vector<bool> cats(n);

  // configure cats
  for (int64_t i = 0; i < n; i++) {
    bool hasCat;
    cin >> hasCat;
    cats[i] = hasCat ? 1 : 0;
  }

  // configure nodes
  for (int64_t i = 0; i < n - 1; i++) {
    int64_t a, b;
    cin >> a >> b;

    nodes[a - 1].push_back(b);
    nodes[b - 1].push_back(a);
  }

  cout << dfs(1, -1, m, nodes, cats, 0) << endl;

  return 0;
}