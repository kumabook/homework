#include <vector>

#define MAX_V 100
using namespace std;

vector<int> G[MAX_V];

int main() {
  int V, E;
  scanf("%d, %d", &V, &E);
  for (int i = 0; i < E; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    G[s].push_back(t);
  }

  return 0;
}
