
#include "sfifo.h"
#include <iostream>

int main() {
  typedef sfifo<int> int_fifo;

  int_fifo myIntFIFO;
  std::cout << "front 0 " << myIntFIFO.front() << std::endl;
  myIntFIFO.push(10);
  std::cout << "front 10 " << myIntFIFO.front() << std::endl;
  myIntFIFO.push(20);
  std::cout << "front 10 " << myIntFIFO.front() << std::endl;
  myIntFIFO.push(30);
  std::cout << "front 10 " << myIntFIFO.front() << std::endl;
  myIntFIFO.push(40);
  std::cout << "front 10 " << myIntFIFO.front() << std::endl;
  myIntFIFO.push(50);
  std::cout << "front 10 " << myIntFIFO.front() << std::endl;

  myIntFIFO.pop();
  std::cout << "front 20 " << myIntFIFO.front() << std::endl;
  myIntFIFO.pop();
  std::cout << "front 30 " << myIntFIFO.front() << std::endl;
  myIntFIFO.pop();
  std::cout << "front 40 " << myIntFIFO.front() << std::endl;
  myIntFIFO.pop();
  std::cout << "front 50 " << myIntFIFO.front() << std::endl;
  myIntFIFO.pop();
  std::cout << "front 0 " << myIntFIFO.front() << std::endl;

  return 0;
}
