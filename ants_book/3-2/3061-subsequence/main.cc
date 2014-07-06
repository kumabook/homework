#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, S;
    scanf("%d %d", &N, &S);
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &sequence[i]);
    }


    int s = 0, t = 0, sum = 0;
    int length = N + 1;

    while (true) {
      while (sum < S && t < N) {
        sum += sequence[t++];
      }
      if (sum < S) {
        break;
      }
      length = min(length, t - s);
      sum -= sequence[s++];
    }
    if (length > N) {
      length = 0;
    }
    printf("%d\n", length);
  }

  return 0;
}
