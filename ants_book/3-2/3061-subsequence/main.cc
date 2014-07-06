#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t = 0; t < T; t++) {
    int N, S;
    scanf("%d %d", &N, &S);
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &sequence[i]);
    }

    vector<int> sum(N);
    sum[0] = sequence[0];
    for (int i = 1; i < N; i++) {
      sum[i] = sum[i - 1] + sequence[i];
    }

    if (sum[N - 1] < S) {
      printf("0\n");
    } else {
      int length = N - 1;
      for (int s = 0; s < N; s++) {
        // sum[end] - sum[start] >= S -------> sum[end] >= S + sum[start - 1]
        int bound = (s == 0 ? 0 : sum[s - 1]) + S;
        int end = lower_bound(sum.begin() + s, sum.end(), bound) - sum.begin();
        if (end == N) {
          break;
        }
        length = min(length, end - s + 1);
      }
      printf("%d\n", length);
    }
  }
  return 0;
}
