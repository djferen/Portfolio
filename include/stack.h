/*
 * This abstract data type stack class provides stack operations with a LIFO queue ordering.
 */
#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include "node.h"

template < class item > struct stack
{
  typedef typename node < item >::link node_link;

  node_link top;

  stack ()
  {
    top = NULL;
  }

  void push (item data)
  {
    node_link link = new node < item > (data, top);
    top = link;
  }

  bool pop (item * data)
  {
    if (top != NULL) {
      *data = top->data;
      node_link temp = top;
      top = top->next;
      delete temp;
      return true;
    }
    return false;
  }

  bool find (item target)
  {
    node_link node = top;
    while (node != NULL) {
      if (node->data == target)
	return true;
      node = node->next;
    }
    return false;
  }

};

#endif
