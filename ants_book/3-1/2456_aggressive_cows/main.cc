#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;


bool check(int N, int M, vector<int> x, int d, queue<int> &results) {
  int pos = x[0];
  results.push(x[0]);
  for (int i = 1; i < N; i++) {
    if (x[i] - pos >= d) {
      results.push(x[i]);
      pos = x[i];
    }
  }
  return results.size() >= M;
}

int main() {
  int N, M;

  cin >> N;
  cin >> M;

  vector<int> x(N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  sort(x.begin(), x.end());

  int d_max = INT_MAX/10-1;
  int d_min = 0;
  int d = 0;

  while (d_max - d_min > 1) {
    queue<int> results;
    d = (d_max + d_min) / 2;
    if (check(N, M, x, d, results)) {
      d_min = d;
    } else {
      d_max = d;
    }
  }
  printf("%d\n", d_min);
  return 0;
}
