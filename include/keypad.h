#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const vector<string> keypad = {"", // 0
                               "", // 1
                               "abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

vector<string> findCombinations(const string &digits) {
  stack<pair<string, int>> combinations;
  combinations.push({"", 0});

  vector<string> results;
  while (!combinations.empty()) {
    string current = combinations.top().first;
    int index = combinations.top().second;
    combinations.pop();

    if (index == digits.size()) {
      if (!current.empty()) {
        results.push_back(current);
      }
      continue;
    }

    int digit = digits[index] - '0';
    for (char letter : keypad[digit]) {
      combinations.push({current + letter, index + 1});
    }
  }

  return results;
}
