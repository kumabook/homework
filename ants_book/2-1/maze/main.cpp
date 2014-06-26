#include <cstdio>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;

int **maze;
int N, M;
int sx, sy;
int gx, gy;

int **d;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs();

int main()
{
  char new_line;
  scanf("%d %d", &N, &M);
  maze = new int*[N];
  d = new int*[N];
  new_line = getchar();
  assert(new_line == '\n');
  for (int i = 0; i < N; i++) {
    maze[i] = new int[M];
    d[i] = new int[M];
    for (int j = 0; j < M; j++) {
      maze[i][j] = (int) getchar();
      d[i][j] = INF;
      if (maze[i][j] == (int) 'S') {
	sx = i;
	sy = j;
	maze[i][j] = '.';
      } else if (maze[i][j] == (int) 'G') {
	gx = i;
	gy = j;
	maze[i][j] = '.';
      }
    }
    new_line = getchar();
    assert(new_line == (int) '\n');
  }

  queue<P> que;

  que.push(P(sx, sy));
  d[sx][sy] = 0;

  while (que.size()) {
    P p = que.front();
    que.pop();

    if (p.first == gx && p.second == gy) {
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M &&
	  maze[nx][ny] != '#' && d[nx][ny] == INF) {
	que.push(P(nx, ny));
	d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }

  printf("%d\n", d[gx][gy]);
}

