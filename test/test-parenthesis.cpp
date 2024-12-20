#include <algorithm>
#include <iostream>
#include <stack>

// Given an arbitrary string of characters, count and return the maximum level
// of nested parentheses.
//  Maximum number of levels that could ever be detected by your function:
//    This is dependent on amount of memory available to the run-time system
//    because a stack data structure was used.
//  O(TIME): N
uint64_t countNestedParentheses(const std::string &str) {
  uint64_t count = 0;
  std::stack<char> counting_stack;
  uint64_t max_count = 0;

  for (char c : str) {
    // Accumulate parenthesis in order and count it if it is balanced
    if ('(' == c) {
      counting_stack.push(c);
    } else if (')' == c && !counting_stack.empty() &&
               '(' == counting_stack.top()) {
      count++;
      counting_stack.pop();
    }
    // When balanced parenthesis have been seen then start counting the next
    // possible ones
    if (count > 0 && counting_stack.empty()) {
      max_count = std::max(max_count, count);
      count = 0;
    }
  }
  return max_count;
}

// TEST CASES FOR COVERAGE
// (Provided Cases)
// 1. Empty Input String
// 2. Singly Nested Parenthesis
// 3. Singly Nested Parenthesis with Unbalanced Parenthesis
// 4. Deeply Nested Parenthesis
// 5. Deeply Nested Parenthesis with Multiple Nested Pairs
//
// (Additional Cases with self explanatory names and test implemetations below)
// 6. Singly Nested Braces
// 7. Totally Unbalanced with Left Parenthesis
// 8. Totally Unbalanced with Right Parenthesis
// 9. Mostly Unbalanced with Left Parenthesis and Singly Nested Parenthesis (L,R
// placement for single as sub cases, L not implemented)
// 10. Mostly Unbalanced with Right Parenthesis and Singly Nested Parenthesis
// (L,R placement for single as sub cases, L not implemented)
// 11. Singly Nested Parenthesis with Offset Start
// 12. Complex Nested Parenthesis
// 13. Deeply Nested Parenthesis with Multiple Nested Pairs with max at end
// 14. Deeply Nested Parenthesis with Multiple Nested Pairs with max in middle

#define TEST(uut, str, expected)                                               \
  {                                                                            \
    uint64_t actual = uut(str);                                                \
    if (actual == expected) {                                                  \
      std::cout << "Passed" << std::endl;                                      \
    } else {                                                                   \
      std::cout << "Failed"                                                    \
                << ": case='" << str << "'"                                    \
                << " expected=" << expected << " actual=" << actual            \
                << std::endl;                                                  \
    }                                                                          \
  }

#define TEST_NESTED_PARENTHESIS(str, expected)                                 \
  TEST(countNestedParentheses, str, expected)

int main() {
  // TEST PROCEDURES
  TEST_NESTED_PARENTHESIS("", 0);
  TEST_NESTED_PARENTHESIS("( )", 1);
  TEST_NESTED_PARENTHESIS("( ) )", 1);
  TEST_NESTED_PARENTHESIS("( 2 + ( 3 * 4 ) )", 2);
  TEST_NESTED_PARENTHESIS("( ( ( 2 * 2 ) + 1 ) / 8 ) ( )", 3);

  // 6. Singly Nested Braces
  TEST_NESTED_PARENTHESIS("[]", 0);
  // 7. Totally Unbalanced with Left Parenthesis
  TEST_NESTED_PARENTHESIS("( ( ( ( ( ( ( (", 0);
  // 8. Totally Unbalanced with Right Parenthesis
  TEST_NESTED_PARENTHESIS("))))))))", 0);
  // 9. Mostly Unbalanced with Left Parenthesis and Singly Nested Parenthesis
  TEST_NESTED_PARENTHESIS("( ( ( ( ( ( ( ( )", 0);
  // 10. Mostly Unbalanced with Right Parenthesis and Singly Nested Parenthesis
  TEST_NESTED_PARENTHESIS(") ) ) ) ) ) ( )", 1);
  // 11. Singly Nested Parenthesis with Offset Start
  TEST_NESTED_PARENTHESIS(" ( )", 1);
  // 12. Complex Nested Parenthesis
  TEST_NESTED_PARENTHESIS(
      "()(()((()()()(())))) (( )( ()()()((((())()(((()()()( ( )", 9);
  // 13. Deeply Nested Parenthesis with Multiple Nested Pairs with max at end
  TEST_NESTED_PARENTHESIS("( ) ( ( ( 2 * 2 ) + 1 ) / 8 )", 3);
  // 14. Deeply Nested Parenthesis with Multiple Nested Pairs with max in middle
  TEST_NESTED_PARENTHESIS("( ) ( ( ( 2 * 2 ) + 1 ) / 8 ) ( )", 3);

  return 0;
}
