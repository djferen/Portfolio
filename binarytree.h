#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <cstddef>
#include "binarytreenode.h"

template < class item > struct binarytree
{
  typedef typename binarytreenode < item >::tree_link binarytree_link;

  binarytree_link root;

    binarytree ()
  {
    root = new binarytreenode < item > ();
  }

  void traverse (binarytree_link h, item target, bool & result);
};

template < class item >
  void binarytree < item >::traverse (binarytree_link h, item target,
				      bool & result)
{
  if (h == NULL) {
    return;
  }
  if (h->data == target) {
    result = true;
    return;
  }
  traverse (h->left);
  traverse (h->right);
}

#endif
