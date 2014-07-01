#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX_N = 1000000;

int main() {
  vector<int> a;
  int n, k;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.push_back(v);
  }
  cin >> k;

  int lb = -1, ub = n;

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (a[mid] >= k) {
      ub = mid;
    } else if (mid < k) {
      lb = mid;
    }
  }

  printf("%d\n", ub);
}
