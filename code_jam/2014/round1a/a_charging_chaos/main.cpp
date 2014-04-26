#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

#define INF 10000000

using namespace std;

bool valid(string outlet, string device, vector<bool> switches) {
  for (int i = 0; i < outlet.size(); i++) {
    if (switches[i]) {
      if (outlet[i] == device[i])
        return false;
    } else {
      if (outlet[i] != device[i])
        return false;
    }
  }
  return true;
}
int find(string outlet, vector<string> devices, vector<bool> switches, vector<int> used) {
  for (int i = 0; i < devices.size(); i++) {
    string device = devices[i];
    if (valid(outlet, device, switches)) {
      bool found = false;
      return i;
      for (int j = 0; j < used.size(); j++) {
        if (used[j] == i) {
          found = true;
        }
      }
      if (!found) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N, L;
    cin >> N, cin >> L;

    int answer = INF;
    vector<string> outlets;
    vector<string> devices;
    for (int n = 0; n < N; n++) {
      string outlet;
      cin >> outlet;
      outlets.push_back(outlet);
    }

    for (int n = 0; n < N; n++) {
      string device;
      cin >> device;
      devices.push_back(device);
    }

    int count;
    for (int j = 0; j < N; j++) {
      vector<bool> switches;
      count = 0;

      for (int l = 0; l < L; l++) {
        string outlet = outlets[0];
        string device = devices[j];
        switches.push_back(outlet[l] != device[l]);
        if (switches[l]) count++;
      }

      bool ok = true;
      vector<int> used;
      for (int n = 0; n < N; n++) {
        int index = find(outlets[n], devices, switches, used);
        if (index < 0) {
          ok = false;
        } else {
          used.push_back(index);
        }
      }
      if (ok && count < answer) {
        answer = count;
      }
    }
    if (answer != INF) {
      printf("Case #%d: %d\n", t, answer);
    } else {
      printf("Case #%d: NOT POSSIBLE\n", t);
    }
  }
}


