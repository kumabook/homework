#include <iostream>

using namespace std;

typedef long long ll;
const int MAX_N = 1000000;

int prime[MAX_N];
bool is_prime[MAX_N + 1];
bool is_prime_small[MAX_N];

int getPrimeNum(int n) {
  int p = 0;

  for (int i = 0; i <= n; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return p;
}

int getPrimeNumOfArea(ll a, ll b) {
  for (int i = 0; (ll) i * i < b; i++) {
    is_prime_small[i] = true;
  }
  for (int i = 0; i < b - a; i++) {
    is_prime[i] = true;
  }

  for (int i = 2; (ll) i * i < b; i++) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll) j * j < b; j += i) {
        is_prime_small[i] = false;
      }
      for (ll j = max(2LL, (a + i -1) / i) * i; j < b; j += i) {
        is_prime[j - a] = false;
      }
    }
  }
  int count = 0;
  for (ll i = a; i < b; i++) {
    if (is_prime[i - a]) {
      count++;
    }
  }
  return count;
}

int main() {
  int n;
  ll a, b;

  //  cin >> n;
  cin >> a >> b;

  //  int p = getPrimeNum(n);
  int p = getPrimeNumOfArea(a, b);
  cout << p << endl;
}
