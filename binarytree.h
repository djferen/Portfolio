/*
 * This abstract binary tree data type allows for tree and BST operations.
 */
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <cstddef>
#include <iostream>
#include "binarytreenode.h"

template < class item > struct binarytree
{
  typedef typename binarytreenode < item >::tree_link binarytree_link;

  binarytree_link root;

    binarytree ()
  {
    root = NULL;
  }

  void push (const item & data);
  void print();
  bool search (item target);
  binarytree_link  searchlink (const item & target);

private:
  binarytree_link  searchlink (binarytree_link h, const item & target);
  bool search (binarytree_link h, item target);
  void push (binarytree_link h, const item & data);
  void print(binarytree_link h);
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
  bool binarytree < item >::search (item target)
{
  return search (root, target);
}

template < class item >
typename binarytree<item>::binarytree_link binarytree < item >::searchlink (const item & target)
{
		return searchlink(root, target);
}

template < class item >
typename binarytree<item>::binarytree_link binarytree < item >::searchlink (binarytree_link h, const item & target)
{
  if (h != NULL) {
    if(target == h->data)
    	return h;
    if(target < h->data)
    	return searchlink(h->left, target);
    else
    	return searchlink(h->right, target);
  }
  else
	  return NULL;
}

template < class item >
  bool binarytree < item >::search (binarytree_link h, item target)
{
  if (h != NULL) {
    if(target == h->data)
    	return true;
    if(target < h->data)
    	return search(h->left, target);
    else
    	return search (h->right, target);
  }
  else
	  return false;
}

template < class item >
void binarytree < item >::print()
{
	print(root);
}

template < class item >
void binarytree < item >::print(binarytree_link h)
{
	if(h != NULL)
	{
	  print(h->left);
	  std::cout << h->data << std::endl;
	  print(h->right);
	}
}

#endif
