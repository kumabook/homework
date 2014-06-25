#include <iostream>

using namespace std;

int extgcd(int a, int b, int& x, int &y);

int main() {
  int a, b, x, y;

  cin >> a >> b;

  int result = extgcd(a, b, x, y);
  if (x > 0) {
    cout << x << " " << 0 << " ";
  } else {
    cout << 0 << " " << -x << " ";
  }

  if (y > 0) {
    cout << y << " " << 0;
  } else {
    cout << 0 << " " << -y;
  }
  cout << endl;

}

int extgcd(int a, int b, int& x, int &y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
