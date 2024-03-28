/*
 * This abstract data type stack class provides stack operations with a LIFO
 * queue ordering.
 */
#ifndef _STACK_H
#define _STACK_H

#include "node.h"

template <typename item_type> struct stack {
  typedef typename node<item_type>::link node_link;

  node_link top;

  stack() { top = nullptr; }

  void push(item_type data) {
    node_link link = new node<item_type>(data, top);
    top = link;
  }

  bool pop(item_type *data) {
    if (top != nullptr) {
      *data = top->data;
      node_link temp = top;
      top = top->next;
      delete temp;
      return true;
    }
    return false;
  }

  bool find(item_type target) {
    node_link node = top;
    while (node != nullptr) {
      if (node->data == target)
        return true;
      node = node->next;
    }
    return false;
  }
};

#endif
