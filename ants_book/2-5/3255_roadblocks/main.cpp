#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>

#define INF 10000000
#define MAX_N 5000

using namespace std;

struct edge { int from, to, cost; };
//struct edge { int to, cost; };
typedef pair<int, int> P;

int main() {
  int N, R;

  vector<edge> edges;
  //  vector<edge> G[MAX_N];

  cin >> N;
  cin >> R;

  for (int i = 0; i < R; i++) {
    int from;
    edge e;
    edge reverse_e;
    cin >> e.from;
    cin >> e.to;
    cin >> e.cost;
    e.from--;
    e.to--;
    edges.push_back(e);
    from = e.from;
    reverse_e.from = e.to;
    reverse_e.to = from;

    reverse_e.cost = e.cost;
    edges.push_back(reverse_e);
  }

  priority_queue<P, vector<P>, greater<P> > que;
  int dist[MAX_N], dist2[MAX_N];
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
    dist2[i] = INF;
  }
  dist[0] = 0;
  que.push(P(0, 0));
  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second,  d = p.first;
    if (dist2[v] < d) continue;
    for (int i = 0; i < edges.size(); i++) {
      //    for (int i = 0; i < G[v].size(); i++) {
      edge e = edges[i];
      //edge &e = G[v][i];
      if (e.from == v) {
        int d2 = d + e.cost;
        if (dist[e.to] > d2) {
          swap(dist[e.to], d2);
          que.push(P(dist[e.to], e.to));
        }
        if (dist2[e.to] > d2 && dist[e.to] < d2) {
          dist2[e.to] = d2;
          que.push(P(dist2[e.to], e.to));
        }
      }
    }
  }

  printf("%d\n", dist2[N-1]);
}
