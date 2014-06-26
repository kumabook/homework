#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX_N 10000


using namespace std;

int main() {
  int L, P, N;
  scanf("%d", &N);
  vector<pair<int,int> > fuels(N + 1);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &fuels[N - 1 - i].first, &fuels[N - 1 - i].second);
  }

  scanf("%d%d", &L, &P);
  fuels[N].first = 0;
  fuels[N].second = 0;
  sort(fuels.begin(), fuels.end(), greater<pair<int,int> >());

  priority_queue<int> que;

  vector<pair<int,int> >::const_iterator it;
  const vector<pair<int,int> >::const_iterator end = fuels.end();

  int ans = 0, pos = 0, tank = P;

  for (it = fuels.begin(); it != end; it++) {
    int d = (L - it->first) - pos;
    //    printf("pos %d , tank %d %d\n", it->first, it->second, d);

    while (tank - d < 0) {
      if (que.empty()) {
	ans = -1;
	printf("%d\n", ans);
	return 0;
      }
      tank += que.top();
      que.pop();
      ans++;
    }
    tank -= d;
    pos = (L - it->first);
    que.push(it->second);
  }

  printf("%d\n", ans);
  return 0;
}
