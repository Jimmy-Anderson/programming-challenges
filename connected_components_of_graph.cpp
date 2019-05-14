#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gb;
vector<int> visited;
int n;
int count = 0;
/*
 * Complete the componentsInGraph function below.
 */
void initialize() {
  for (int i = 0; i <= 15000; i++)
    visited.push_back(0);
}
void dfs(int s) {
  visited[s] = 1;
  ::count++;
  for (int i = 0; i < gb[s].size(); i++)
    if (visited[gb[s][i]] == 0)
      dfs(gb[s][i]);
}
void componentsInGraph() {
  initialize();
  vector<int> arr_count;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      arr_count.push_back(::count);
      ::count = 0;
    }
  }
  int max = 2, min = 15000;
  for (int i = 0; i < arr_count.size(); i++) {
    if (arr_count[i] > max && arr_count[i] != 1)
      max = arr_count[i];
    if (arr_count[i] < min && arr_count[i] != 1)
      min = arr_count[i];
  }
  cout << min << " " << max << "\n";
}

int main() {
  cin >> n;
  for (int i = 0; i <= 15000; i++) {
    vector<int> a;
    gb.push_back(a);
  }
  int x = n;
  int g, b;
  while (x--) {
    cin >> g >> b;
    gb[g].push_back(b);
    gb[b].push_back(g);
  }
  componentsInGraph();
  return 0;
}
