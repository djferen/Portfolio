/*
 * This abstract binary tree data type allows for tree and BST operations.
 */
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "binarytreenode.h"
#include <iostream>

template <typename item_type> struct binarytree {
  typedef typename binarytreenode<item_type>::tree_link binarytree_link;

  binarytree_link root;

  binarytree() { root = nullptr; }

  void push(const item_type &data);
  void print();
  bool search(item_type target);
  binarytree_link searchlink(const item_type &target);

private:
  binarytree_link searchlink(binarytree_link h, const item_type &target);
  bool search(binarytree_link h, item_type target);
  void push(binarytree_link h, const item_type &data);
  void print(binarytree_link h);
};

template <typename item_type>
void binarytree<item_type>::push(const item_type &data) {
  if (root == nullptr) {
    root = new binarytreenode<item_type>(data, nullptr, nullptr, nullptr);
    return;
  }

  push(root, data);
}

template <typename item_type>
void binarytree<item_type>::push(binarytree_link h, const item_type &data) {
  if (data < h->data) {
    if (h->left == nullptr) {
      h->left = new binarytreenode<item_type>(data, h, nullptr, nullptr);
    } else {
      push(h->left, data);
    }
  } else if (data > h->data) {
    if (h->right == nullptr) {
      h->right = new binarytreenode<item_type>(data, h, nullptr, nullptr);
    } else {
      push(h->right, data);
    }
  }
}

template <typename item_type>
bool binarytree<item_type>::search(item_type target) {
  return search(root, target);
}

template <typename item_type>
typename binarytree<item_type>::binarytree_link
binarytree<item_type>::searchlink(const item_type &target) {
  return searchlink(root, target);
}

template <typename item_type>
typename binarytree<item_type>::binarytree_link
binarytree<item_type>::searchlink(binarytree_link h, const item_type &target) {
  if (h != nullptr) {
    if (target == h->data)
      return h;
    if (target < h->data)
      return searchlink(h->left, target);
    else
      return searchlink(h->right, target);
  } else
    return nullptr;
}

template <typename item_type>
bool binarytree<item_type>::search(binarytree_link h, item_type target) {
  if (h != nullptr) {
    if (target == h->data)
      return true;
    if (target < h->data)
      return search(h->left, target);
    else
      return search(h->right, target);
  } else
    return false;
}

template <typename item_type> void binarytree<item_type>::print() {
  print(root);
}

template <typename item_type>
void binarytree<item_type>::print(binarytree_link h) {
  if (h != nullptr) {
    print(h->left);
    std::cout << h->data << std::endl;
    print(h->right);
  }
}

#endif
