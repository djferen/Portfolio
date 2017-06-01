/*
 * This abstract data type fifo provides a FIFO queue data structure.
 */
#ifndef _FIFO_H
#define _FIFO_H

#include "doublylinkednode.h"

template < typename item_type >
struct fifo
{
  typedef typename doublylinkednode < item_type >::link doublylinkednode_link;

  doublylinkednode_link h;
  doublylinkednode_link t;

  fifo ()
  {
    h = nullptr;
    t = nullptr;
  }

  void enqueue (item_type * list, int length)
  {
    for (int i = 0; i < length; i++) {
      enqueue (list[i]);
    }
  }

  void enqueue (item_type data)
  {
    doublylinkednode_link newnode =
      new doublylinkednode < item_type > (data, h, nullptr);
    if (h) {
      h->prev = newnode;
    }
    h = newnode;
    if (t == nullptr) {
      t = newnode;
    }
  }

  bool dequeue (item_type * data)
  {
    if (t != nullptr) {
      *data = t->data;
      doublylinkednode_link temp = t;
      t = t->prev;
      delete temp;
      return true;
    }
    return false;
  }

  void append (item_type data)
  {
    doublylinkednode_link newnode =
      new doublylinkednode < item_type > (data, nullptr, t);
    if (t) {
      t->next = newnode;
    }
    t = newnode;
  }

  bool find (item_type target)
  {
    doublylinkednode_link node = h;
    while (node != nullptr) {
      if (node->data == target)
        return true;
      node = node->next;
    }
    return false;
  }

};

#endif
