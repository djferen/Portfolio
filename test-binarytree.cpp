
#include <string>
#include <iostream>
#include "binarytree.h"

int
main ()
{
  binarytree < std::string > myBinaryTree;

  myBinaryTree.push ("d");
  myBinaryTree.push ("b");
  myBinaryTree.push ("g");
  myBinaryTree.push ("a");
  myBinaryTree.push ("c");
  myBinaryTree.push ("e");
  myBinaryTree.push ("f");
  myBinaryTree.push ("f1");
  myBinaryTree.push ("f2");
  myBinaryTree.push ("f3");
  myBinaryTree.push ("f4");
  myBinaryTree.push ("z");

  bool result = false;

  result = myBinaryTree.search ("a");
  std::cout << "Searched for a" << (result ? " found" : " not found") << std::
    endl;

  result = myBinaryTree.search ("b");
  std::cout << "Searched for b" << (result ? " found" : " not found") << std::
    endl;

  result = myBinaryTree.search ("f");
  std::cout << "Searched for f" << (result ? " found" : " not found") << std::
    endl;

  result = myBinaryTree.search ("h");
  std::cout << "Searched for h" << (result ? " found" : " not found") << std::
    endl;

  myBinaryTree.print();

  binarytree < std::string >::binarytree_link link = myBinaryTree.searchlink("a");
  std::cout << "Searched for a" << (link != NULL ? " found" : " not found") << std::endl;

  link = myBinaryTree.searchlink("zz");
  std::cout << "Searched for zz" << (link != NULL ? " found" : " not found") << std::endl;

  return 0;
}
