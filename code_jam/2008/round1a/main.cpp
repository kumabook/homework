#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {

    vector<long long> v1;
    vector<long long> v1_negative;
    vector<long long> v2;
    vector<long long> v2_negative;
    int n;
    cin >> n;

    for (int j = 1; j <= n; j++) {
      int val; cin >> val;
      if (val < 0)  v1_negative.push_back(val);
      else v1.push_back(val);
    }
    for (int j = 1; j <= n; j++) {
      int val; cin >> val;
      if (val < 0) v2_negative.push_back(val);
      else v2.push_back(val);
    }

    sort(v1.begin(), v1.end());
    sort(v1_negative.begin(), v1_negative.end());
    sort(v2.begin(), v2.end());
    sort(v2_negative.begin(), v2_negative.end());

    long long total = 0;
    int remain = n;
    //    printf("problem %d %d \n" ,i, n);
    while (remain > 0) {
      //      printf("problem %d total %d remain %d\n" , total, i, remain);
      if (v1_negative.size() == 0 && v2_negative.size() == 0) {
        // most big x most small
        if (v1.back() > v2.back()) {
          total += v1.back() * v2[0];
          v1.pop_back();
          v2.erase(v2.begin());
        } else {
          total += v2.back() * v1[0];
          v2.pop_back();
          v1.erase(v1.begin());
        }
      } else {
        // most small x most big
        if (v1_negative.size() > 0 &&
            (v2_negative.size() == 0 || v2_negative[0] <= v1_negative[0])) {
          if (v2.size() > 0) {
            total += v1_negative[0] * v2.back();
            v2.pop_back();
            v1_negative.erase(v1_negative.begin());
          } else {
            total += v1_negative[0] * v2_negative.back();
            v2_negative.pop_back();
            v1_negative.erase(v1_negative.begin());
          }
        } else {
          if (v1.size() > 0) {
            total += v2_negative[0] * v1.back();
            v1.pop_back();
            v2_negative.erase(v2_negative.begin());
          } else {
            total += v2_negative[0] * v1_negative.back();
            v1_negative.pop_back();
            v2_negative.erase(v2_negative.begin());
          }
        }
      }
      remain--;
    }
    printf("Case #%d: %d\n", i, total);
  }
}
