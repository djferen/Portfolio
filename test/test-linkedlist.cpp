
#include <iostream>
#include "linkedlist.h"
#include <utility>

int
main ()
{
  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  typedef linkedlist <int> int_ll_type;

  int_ll_type a_int_ll(iarray, isize);

  std::cout << "At initialization, a_int_ll contains: " << a_int_ll << std::endl;

  a_int_ll.reverseByStack();

  std::cout << "After reverse via stack; a_int_ll contains: " << a_int_ll << std::endl;

  a_int_ll.reverseByPtr();

  std::cout << "After reverse via pointer; a_int_ll contains: " << a_int_ll << std::endl;

  int_ll_type b_int_ll(a_int_ll);

  std::cout << "After copy, a_int_ll contains: " << a_int_ll << std::endl;

  std::cout << "After copy, b_int_ll contains: " << b_int_ll << std::endl;

  size_t csize = 10;
  int carray[csize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int_ll_type c_int_ll (carray, csize);

  std::cout << "After init, c_int_ll contains: " << c_int_ll << std::endl;

  std::cout << "Before move, a_int_ll contains: " << a_int_ll << std::endl;

  int_ll_type d_int_ll = std::move(a_int_ll);

  std::cout << "After move, a_int_ll contains: " << a_int_ll << std::endl;

  std::cout << "After move, d_int_ll contains: " << d_int_ll << std::endl;

  std::cout << "d_int_ll has cycle: " << (d_int_ll.containsCycle() ? "true" : "false") << std::endl;

  int_ll_type::linktype mid_link = d_int_ll.getLink(3);

  int_ll_type::linktype tail_node = d_int_ll.getTailNode();

  std::cout << "d_int_ll has cycle: " << (d_int_ll.containsCycle() ? "true" : "false") << std::endl;

  int_ll_type empty_int_ll;

  std::cout << "empty_int_ll has cycle: " << (empty_int_ll.containsCycle() ? "true" : "false") << std::endl;

  return 0;
}
