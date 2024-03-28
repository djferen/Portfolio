
#include "fifo.h"
#include <iostream>

int main() {
  typedef fifo<int> int_fifo;

  int_fifo myIntFIFO;

  myIntFIFO.enqueue(10);
  myIntFIFO.enqueue(20);
  myIntFIFO.enqueue(30);
  myIntFIFO.enqueue(40);
  myIntFIFO.enqueue(50);
  myIntFIFO.append(50);

  int mylist[3] = {100, 200, 300};
  myIntFIFO.enqueue(mylist, 3);

  if (myIntFIFO.find(30))
    std::cout << "Found 30" << std::endl;

  int temp;
  while (myIntFIFO.dequeue(&temp)) {
    std::cout << "dequeue returned " << temp << std::endl;
  }

  return 0;
}
