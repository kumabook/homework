#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 100000;

bool check(vector<int> w, vector<int> v, int n, int k, double x) {
  vector<double> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i] = v[i] - x * w[i];
  }

  sort(tmp.begin(), tmp.end());
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += tmp[n - i - 1];
  }
  return sum >= 0;
}

int main() {
  int n, k;

  cin >> n;
  cin >> k;

  vector<int> w(n);
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }

  double lb = 0;
  double ub = MAX;

  for(int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (check(w, v, n, k, mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.2f\n", lb);
}
