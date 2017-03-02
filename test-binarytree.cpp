
#include <string>
#include <iostream>
#include "binarytree.h"

int
main ()
{
  binarytree < std::string > myBinaryTree;

  myBinaryTree.push ("a");
  myBinaryTree.push ("b");
  myBinaryTree.push ("c");
  myBinaryTree.push ("d");
  myBinaryTree.push ("e");
  myBinaryTree.push ("f");
  myBinaryTree.push ("g");

  bool result = false;

  myBinaryTree.search ("a", result);
  std::cout << "Searched for a" << (result ? " found" : " not found") << std::
    endl;

  myBinaryTree.search ("b", result);
  std::cout << "Searched for b" << (result ? " found" : " not found") << std::
    endl;

  myBinaryTree.search ("f", result);
  std::cout << "Searched for f" << (result ? " found" : " not found") << std::
    endl;

  myBinaryTree.search ("h", result);
  std::cout << "Searched for h" << (result ? " found" : " not found") << std::
    endl;

  return 0;
}
