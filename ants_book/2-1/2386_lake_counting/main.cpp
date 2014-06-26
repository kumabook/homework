#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

void dfs(int x, int y);

int N, M;
char **field;

int main()
{
  char new_line;
  scanf("%d %d", &N, &M);
  field = new char*[N];
  new_line = getchar();
  assert(new_line == '\n');
  for (int i = 0; i < N; i++) {
    field[i] = new char[M];
    for (int j = 0; j < M; j++) {
      field[i][j] = getchar();
    }
    new_line = getchar();
    assert(new_line == '\n');
  }

  int lake_count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == 'W') {
        dfs(i, j);
        lake_count++;
      }
    }
  }
  printf("%d\n", lake_count);
}

void dfs(int x, int y) {
  field[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < N &&
          0 <= ny && ny < M && field[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
}
