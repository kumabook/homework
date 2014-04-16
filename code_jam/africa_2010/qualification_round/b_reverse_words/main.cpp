#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &str, char delim) {
  vector<string> result;
  size_t current = 0, found;
  while ((found = str.find_first_of(delim, current)) != string::npos) {
    result.push_back(string(str, current, found- current));
    current = found + 1;
  }
  result.push_back(string(str, current, str.size() - current));
  return result;
}

int main()
{
  int N;
  cin >> N;
  cin.ignore();

  for (int i = 1; i <= N; i++) {
    string line;
    getline(cin, line);

    vector<string> words = split(line, ' ');
    vector<string> reverse_words;
    printf("Case #%d:", i);
    for (int j = words.size() - 1; j >= 0; j--) {
      cout << ' ';
      cout << words[j];
    }
    cout << endl;
  }
}
