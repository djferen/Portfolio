
#include <iostream>
#include "linkedlist.h"

int
main ()
{
  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  linkedlist < int > int_ll(iarray, isize);

  std::cout << "At initialization, int_ll contains: " << int_ll << std::endl;

  int_ll.reverseByStack();

  std::cout << "After reverse via stack; int_ll contains: " << int_ll << std::endl;

  int_ll.reverseByPtr();

  std::cout << "After reverse via pointer; int_ll contains: " << int_ll << std::endl;

  int_ll.reverseByStack();

  std::cout << "After reverse via stack; int_ll contains: " << int_ll << std::endl;

  int_ll.reverseByPtr();

  std::cout << "After reverse via pointer; int_ll contains: " << int_ll << std::endl;

  return 0;
}
