/*
 * This abstract binary tree node data type is to be used in binary tree
 * operations.
 */
#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_

template <typename item_type> struct binarytreenode {
  typedef binarytreenode<item_type> *tree_link;

  tree_link parent;
  tree_link left;
  tree_link right;
  item_type data;

  binarytreenode(item_type data, tree_link parent, tree_link left,
                 tree_link right) {
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
  }

  binarytreenode(item_type data) {
    this->data = data;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  binarytreenode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

#endif
