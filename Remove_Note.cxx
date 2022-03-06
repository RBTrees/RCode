#include <iostream>
#include <string>

using namespace std;

string s, target = "--------------------\n";

signed main() {
  for (string t; getline(cin, t); s += t + '\n') {
  }
  while (s.back() == '\n') {
    s.pop_back();
  }
  s.push_back('\n');
  for (uintmax_t i = 1; i < s.size(); ++i) {
    char x = s[i - 1], y = s[i];
    if (x == '/' && y == '/') {
      ++i;
      while (s[i] != '\n') {
        ++i;
      }
    } else if (x == '/' && y == '*') {
      ++i;
      while (s[i] != '*' || s[i + 1] != '/') {
        ++i;
      }
      ++ ++i;
    } else {
      target.push_back(x);
    }
  }
  while (target.front() == '\n') {
    target = target.substr(1);
  }
  while (target.back() == '\n' || target.back() == ' ') {
    target.pop_back();
  }
  cout.rdbuf()->sputn(target.c_str(), target.size());
  return 0;
}
