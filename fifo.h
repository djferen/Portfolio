#ifndef _FIFO_H
#define _FIFO_H

#include <cstddef>
#include "doublylinkednode.h"

template <class item>
struct fifo
{
  typedef typename doublylinkednode<item>::link doublylinkednode_link;

  doublylinkednode_link h;
  doublylinkednode_link t;

  fifo ()
  {
    h = NULL;
    t = NULL;
  }

  void enqueue (item *list, int length)
  {
    for (int i = 0; i < length; i++) {
      enqueue (list[i]);
    }
  }

  void enqueue (item data)
  {
    doublylinkednode_link newnode = new doublylinkednode<item>(data, h, NULL);
    if (h)
    {
      h->prev = newnode;
    }
    h = newnode;
    if (t == NULL)
    {
      t = newnode;
    }
  }

  bool dequeue (item *data)
  {
    if (t != NULL)
    {
      *data = t->data;
      doublylinkednode_link temp = t;
      t = t->prev;
      delete temp;
      return true;
    }
    return false;
  }

  void append (item data)
  {
    doublylinkednode_link newnode = new doublylinkednode<item> (data, NULL, t);
    if (t) {
      t->next = newnode;
    }
    t = newnode;
  }

  bool find (item target)
  {
    doublylinkednode_link node = h;
    while (node != NULL)
    {
      if (node->data == target)
	     return true;
      node = node->next;
    }
    return false;
  }

};

#endif

