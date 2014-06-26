#include <vector>
#include <iostream>

using namespace std;

#define INF 10000000

struct relation { int x, y, cost; };

int main()
{
  int TOTAL;
  int N, M, R;

  cin >> TOTAL;

  for (int i = 1; i <= TOTAL; i++) {
    cin >> N; cin >> M; cin >> R;
    vector<relation> relations;
    for (int j = 1; j <= R; j++) {
      relation r;
      cin >> r.x; cin >> r.y; cin >> r.cost;
      r.cost = 10000 - r.cost;
      relations.push_back(r);
    }
    
  }
}
