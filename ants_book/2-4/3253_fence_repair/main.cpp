#include <stdio.h>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

int main()
{
  int N;
  int *planks;
  int length = 0;
  long long answer = 0;
  scanf("%d\n", &N);
  planks = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d\n", planks + i);
    length += planks[i];
  }

  while (N > 1) {
    int mii1 = 0, mii2 = 1;
    if (planks[mii1] > planks[mii2]) std::swap(mii1, mii2);
    for (int i = 2; i < N; i++) {
      if (planks[i] < planks[mii1]) {
	mii2 = mii1;
	mii1 =i;
      } else if (planks[i] < planks[mii2]) {
	mii2 = i;
      }
    }
    
    int t = planks[mii1] + planks[mii2];
    answer += t;

    if (mii1 == N - 1) std::swap(mii1, mii2);

    planks[mii1] = t;
    planks[mii2] = planks[N - 1];

    N--;
  }

  printf("%lld\n", answer);

  delete planks;
}
