#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int case_cnt;
  scanf("%d", &case_cnt);

  while (case_cnt--) {
    int pole_length;
    int ants_number;
    int maxT = 0, minT = 0;
    int a;

    scanf("%d%d", &pole_length, &ants_number);

    for (int i = 0; i < ants_number; i++) {
      scanf("%d", &a);
      minT = max(minT, min(a, pole_length - a));
      maxT = max(maxT, max(a, pole_length - a));
    }

    printf("%d %d\n", minT, maxT);
  }
  return 0;
}

