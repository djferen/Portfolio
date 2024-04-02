#include <iostream>
#include <map>

using namespace std;

// Problem
//    Given a string of characters, return the index of the first non-repeating character.
// Example
//    Input: "abcdcaf"
//    Output: 1

int find_unique(string s)
{
    /*
    map<char><size_t> occurences;
    map<char><size_t>::iterator it;

    for(auto _char; s)
    {
        it = occurences.find(_char);
        if(it != mymap.end()) {
            it->
        }
        occurences.push_back()
    }
    */
    return -1;
}

int main() {
  size_t tests = 3;
  string input[tests] = {"", "abcdcaf", "aabbcc"};
  int expected_results[tests] = {-1, 1, -1};

  int actual, expected;

  for (size_t i = 0; i < tests; i++) {
    actual = find_unique(input[i]);
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
