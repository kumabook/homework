#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int C, I;

    cin >> C;
    cin >> I;

    int*origin = new int[I];
    int*work = new int[I];

    for (int j = 0; j < I; j++) {
      cin >> work[j];
    }

    int first, second;
    int diff = C;
    for (int j = I - 1; j >= 0; j--) {
      for (int k = j - 1; k >= 0; k--) {
        int _diff = C - work[j] - work[k];
        if (_diff >= 0 && _diff < diff) {
          diff = _diff;
          first = j;
          second = k;
        }
      }
    }

    if (first < second) {
      printf("Case #%d: %d %d\n", i, first+1, second+1);
    } else {
      printf("Case #%d: %d %d\n", i, second+1, first+1);
    }
  }
}
