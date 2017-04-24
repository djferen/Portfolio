
#include <iostream>
#include "minheap.h"

int
main ()
{
  typedef minheap < int > int_minheap_type;

  int_minheap_type  int_minheap;

  int_minheap.add(40);
  int_minheap.add(20);
  int_minheap.add(50);
  int_minheap.add(30);
  int_minheap.add(0);
  int_minheap.add(10);

  int_minheap.print();

  return 0;
}
