#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
public:
  typedef std::stack<int> stack_type;

  stack_type input_stack, output_stack;

  MyQueue() {}

  void push(int x) { input_stack.push(x); }

  void pop() {
    if (!output_stack.empty()) {
      output_stack.pop();
    } else {
      while (!input_stack.empty()) {
        output_stack.push(input_stack.top());
        input_stack.pop();
      }

      if (!output_stack.empty()) {
        output_stack.pop();
      }
    }
  }

  int front() {
    if (output_stack.empty()) {
      while (!input_stack.empty()) {
        output_stack.push(input_stack.top());
        input_stack.pop();
      }
    }

    return output_stack.top();
  }
};

int main() {
  MyQueue q1;
  int q, type, x;

  std::stringstream ss;
  ss << "10 1 42 2 1 14 3 1 28 3 1 60 1 78 2 2";

  ss >> q;
  for (int i = 0; i < q; i++) {
    ss >> type;
    if (type == 1) {
      ss >> x;
      q1.push(x);
    } else if (type == 2) {
      q1.pop();
    } else
      cout << q1.front() << endl;
  }

  return 0;
}
