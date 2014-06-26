#include <cstdio>
#include <algorithm>

using namespace std;

void solve(int R, int N, int *positions) {
  int count = 0;
  int i = 0;
  int left;
  while (i < N) {
    left = positions[i];
    i++;
    for (int j = i; j < N; j++) {
      if (positions[j] - left <= R) i++;
      else break;
    }
    int point_index = i - 1;
    i = point_index + 1;
    for (int k = point_index + 1; k < N; k++) {
      if (positions[k] - positions[point_index] <= R) {
	i = k + 1;
      }
    }
    count++;
  }
  printf("%d\n", count);
}

int main()
{
  int R, N;
  int *positions;
  int count;

  while (true) {
    scanf("%d %d\n", &R, &N);
    if (R == -1 || N == -1) break;
    positions = new int[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", &positions[i]);
      getchar();
    }

    sort(positions, positions + N);
    solve(R, N, positions);
    delete positions;
  }
}
