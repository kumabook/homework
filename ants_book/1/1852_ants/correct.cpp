#include<cstdio>
#include<algorithm>

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    int L, N, a, b, t;
    scanf("%d%d", &L, &N);
    a = 0; b = 0;
    for(int i=0; i<N; ++i) {
      scanf("%d", &t);
      a = std::max(a, std::min(t, L-t));
      b = std::max(b, std::max(t, L-t));
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
