#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string LetterCapitalize(string str) {
  string result;
  int word_length = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      result += str[i];
      word_length = 0;
    } else {
      if (word_length == 0 && str[i] >= 'a' && str[i] <= 'z') {
        result += str[i] - 32;
      } else {
        result += str[i];
      }
      word_length++;
    }
  }
  return result;
}

int main() {
  size_t tests = 8;
  string test[tests][2] = {{"", ""},
                           {"A", "A"},
                           {" a ", " A "},
                           {"A aB c ", "A AB C "},
                           {"ab cd2123", "AbCd2123"},
                           {"###3# ##", "###3# ##"},
                           {"cc", "Cc"},
                           {"sjafs afsf asfas", "Sjafs Afsf Asfas"}};

  string input;
  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    input = test[i][0];
    actual = LetterCapitalize(input);
    expected = test[i][1];
    cout << "Case #" << i + 1 << " input: '" << input << "' expected: '"
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
