
#include "stack.h"
#include <iostream>

int main() {
  typedef stack<int> int_stack;

  int_stack myIntStack;

  myIntStack.push(0);
  myIntStack.push(10);
  myIntStack.push(20);
  myIntStack.push(30);
  myIntStack.push(40);
  myIntStack.push(50);

  if (myIntStack.find(30))
    std::cout << "Found 30" << std::endl;

  int temp;
  while (myIntStack.pop(&temp)) {
    std::cout << "pop returned " << temp << std::endl;
  }

  return 0;
}
