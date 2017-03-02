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
    root = NULL;
  }

  void search (item target, bool & result);
  void push (const item & data);

private:
  void search (binarytree_link h, item target, bool & result);
  void push (binarytree_link h, const item & data);
};

template < class item > void binarytree < item >::push (const item & data)
{
  if (root == NULL) {
    root = new binarytreenode < item > (data, NULL, NULL, NULL);
    return;
  }

  push (root, data);
}

template < class item >
  void binarytree < item >::push (binarytree_link h, const item & data)
{
  if (data < h->data) {
    if (h->left == NULL) {
      h->left = new binarytreenode < item > (data, h, NULL, NULL);
    }
    else {
      push (h->left, data);
    }
  }
  else if (data > h->data) {
    if (h->right == NULL) {
      h->right = new binarytreenode < item > (data, h, NULL, NULL);
    }
    else {
      push (h->right, data);
    }
  }
}

template < class item >
  void binarytree < item >::search (item target, bool & result)
{
  search (root, target, result);
}

template < class item >
  void binarytree < item >::search (binarytree_link h, item target,
				    bool & result)
{
  if (h == NULL) {
    result = false;
    return;
  }
  if (h->data == target) {
    result = true;
    return;
  }
  search (h->left, target, result);
  search (h->right, target, result);
}

#endif
