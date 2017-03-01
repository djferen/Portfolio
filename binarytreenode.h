#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_

#include <cstddef>

template < class item > struct binarytreenode
{
  typedef binarytreenode < item > *tree_link;

  tree_link parent;
  tree_link left;
  tree_link right;
  item data;

    binarytreenode (item data, tree_link parent, tree_link left,
		    tree_link right)
  {
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
  }

  binarytreenode (item data)
  {
    this->data = data;
    parent = NULL;
    left = NULL;
    right = NULL;
  }

  binarytreenode () {
    parent = NULL;
    left = NULL;
    right = NULL;
  }
};

#endif
