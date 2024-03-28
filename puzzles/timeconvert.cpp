#include <iostream>
#include <sstream>
using namespace std;

/*
The function TimeConvert(num) take the num parameter being passed and
return the number of hours and minutes the parameter converts to (ie. if num =
63 then the output should be 1:3). Separate the number of hours and minutes with
a colon.

Sample Test Cases
Input:126
Output:"2:6"

Input:45
Output:"0:45"
*/

string TimeConvert(int time) {
  stringstream ss;

  if (time <= 0) {
    ss << "0:0";
  } else {
    ss << (time / 60) << ":" << (time % 60);
  }
  return ss.str();
}

int main() {
  size_t tests = 5;
  int input[tests] = {-1, 0, 10, 100, 1000};
  string expected_results[tests] = {"0:0", "0:0", "0:10", "1:40", "16:40"};

  string actual;
  string expected;

  for (size_t i = 0; i < tests; i++) {
    actual = TimeConvert(input[i]);
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
