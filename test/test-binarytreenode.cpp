
#include "binarytreenode.h"

int
main ()
{
  typedef binarytreenode < int >int_binarytreenode;
  typedef binarytreenode < int >::tree_link int_binarytree_link;

  int_binarytree_link myBinaryTree =
    new int_binarytreenode (0, NULL, NULL, NULL);

  return 0;
}
