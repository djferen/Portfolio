
#include <keypad.h>

int main() {
  int number = 919;

  string digits = to_string(number);

  vector<string> results = findCombinations(digits);

  if (results.empty()) {
    cout << "No letter combinations found." << endl;
  } else {
    cout << "Possible letter combinations:" << endl;
    for (const string &combination : results) {
      cout << combination << endl;
    }
  }

  return 0;
}