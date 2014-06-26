#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b);

int main() {
  int x1, y1;
  int x2, y2;
  cin >> x1 >> y1;
  cin >> x2 >> y2;

  cout << gcd(abs(x1 - x2), abs(y1 - y2)) << endl;

  //  cout << x1 << y1 << endl;
  //  cout << x2 << y2 << endl;

}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
