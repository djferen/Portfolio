#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_balanced(string expression) {
  stack<char> s;
  bool pushed = false;

  for (auto c : expression) {
    if (c == '[')
      s.push(']');
    else if (c == '{')
      s.push('}');
    else if (c == '(')
      s.push(')');
    else {
      if (!s.empty() && s.top() == c)
        s.pop();
    }
    if (!s.empty()) {
      pushed = true;
    }
  }

  return s.empty() && (pushed && expression.length() > 0);
}

int main() {
  ifstream inf("./test/bb-test", ifstream::in);
  ifstream einf("./test/bb-exp", ifstream::in);

  int n;
  inf >> n;

  string input, expected;

  for (int i = 0; i < n; i++) {
    inf >> input;
    einf >> expected;
    string actual = (is_balanced(input) ? "YES" : "NO");

    if (actual != expected) {
      cout << "Actual != expected for " << n << endl << input << endl;
    }
  }

  inf.close();
  einf.close();

  return 0;
}
