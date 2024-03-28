#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*

The function AlphabetSoup(str) take the str string parameter being passed and
return the string with the letters in alphabetical order (ie. hello becomes
ehllo). Assume numbers and punctuation symbols will not be included in the
string.

Sample Test Cases
Input:"coderbyte"
Output:"bcdeeorty"

Input:"hooplah"
Output:"ahhloop"

*/

vector<char> ToV(string input) {
  vector<char> v;
  for (size_t i = 0; i < input.length(); i++) {
    v.push_back(input[i]);
  }
  return v;
}

string ToS(vector<char> input) {
  string s;
  for (size_t i = 0; i < input.size(); i++) {
    s += input[i];
  }
  return s;
}

string AlphabetSoup(string str) {
  vector<char> v = ToV(str);

  std::sort(v.begin(), v.end());

  return ToS(v);
}

int main() {
  size_t tests = 5;
  string input[tests] = {"", "coderbyte", "hoopla", "cba", "l2eqlndonr2on"};
  string expected_results[tests] = {"", "bcdeeorty", "ahloop", "abc",
                                    "22dellnnnooqr"};

  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    actual = AlphabetSoup(input[i]);
    expected = expected_results[i];
    cout << "Case #" << i + 1 << " input: '" << input[i] << "' expected: '"
         << expected << "' actual: '" << actual << "'" << endl;
    if (actual != expected) {
      cout << "Test failed!" << endl;
    } else {
      cout << "Test passed!" << endl;
    }
    cout << endl;
  }

  return 0;
}
