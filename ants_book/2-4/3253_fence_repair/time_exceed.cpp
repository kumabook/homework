#include <stdio.h>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

int main()
{
  int N;
  list<int> planks;
  int length = 0;
  long long answer = 0;
  int temp;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d\n", &temp);
    length += temp;
    planks.push_back(temp);
  }

  planks.sort();

  while (N > 1) {

    int t = 0;
    int a;
    a = planks.front();
    t += a;
    planks.pop_front();

    a = planks.front();
    t += a;

    answer += t;
    if (planks.front() == 0) {
      break;
    }
    planks.pop_front();
    list<int>::iterator it = planks.begin();
    while (true) {
      if (*it > t) {
	planks.insert(it, t);
	break;
      } else if (it == planks.end()) {
	planks.insert(it, t); 
	break;
      }
      ++it;
    }
    N--;
  }

  printf("%lld\n", answer);

}
