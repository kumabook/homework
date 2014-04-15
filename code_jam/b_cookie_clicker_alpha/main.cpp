#include <cstdio>
#include <algorithm>
#include <cassert>

#define DEBUG 0

using namespace std;


static double C, F, X;
static int i;
static double total_time;

int main()
{
  int count;
  scanf("%d", &count);

  for (i = 1; i <= count; i++) {
    double time = 0;
    double c_per_sec = 2.0;
    double currentTime = 0.0;
    int cookies = 0;

    scanf("%lf %lf %lf", &C, &F, &X);
    total_time = X / c_per_sec;

#if DEBUG
    printf("Case #%d solving %lf %lf %lf\n", i, C, F, X);
#endif
    while (true) {
      double fac_time = C / c_per_sec;
      double time = X / c_per_sec;
#if DEBUG
      printf("  c_per_sec %lf currentTime %lf\n", c_per_sec, currentTime);
      printf("  c_per_sec %lf fac_time %lf time %lf\n", c_per_sec, fac_time, time);
      printf(" total time %lf\n", currentTime + time);
#endif
      if (currentTime + time < total_time) {
        total_time = currentTime + time;
      }

      if (time <= fac_time) {
        break;
      }
      if (currentTime + fac_time < total_time) {
        c_per_sec = c_per_sec + F;
        currentTime = currentTime + fac_time;
      } else {
        break;
      }
    }
    printf("Case #%d: %.7lf\n", i, total_time);
  }
}
