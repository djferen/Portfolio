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
  int n = 0;
  const string infile = "../test/bb-test";
  const string expfile = "../test/bb-exp";
  ifstream inf(infile, ifstream::in);
  ifstream einf(expfile, ifstream::in);

  if (!inf) {
    cerr << "Unable to open file: " << infile << endl;
    return -1;
  }

  inf >> n;

  if (!einf) {
    cerr << "Unable to open file: " << expfile << endl;
    return -1;
  }

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
