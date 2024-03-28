
#include "node.h"

int main() {
  typedef node<int> int_node;

  typedef int_node::link int_node_link;

  int_node::link link = new int_node(0, nullptr);

  return 0;
}
