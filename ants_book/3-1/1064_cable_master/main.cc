#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdio>
const double INF = (1 << 20);

using namespace std;

bool check(vector<double> &cables, double c, int k);

int main() {
  int n, k;


  cin >> n >> k;
  vector<double> cables(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &cables[i]);
  }

  double min = 0;
  double max = INF;

  for (int i = 0; i < 100; ++i) {
    double len = (min + max) / 2.0;

    if (check(cables, len, k)) {
      min = len;
    } else {
      max = len;
    }
  }
  printf("%.2f\n", floor(max * 100) / 100);
}

bool check(vector<double> &cables, double c, int k) {
  int n = 0;
  int l = cables.size();
  for (int i = 0; i < l; ++i) {
    n += floor(cables[i] / c);
  }
  return n >= k;
}
