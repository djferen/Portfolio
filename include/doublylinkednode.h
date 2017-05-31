/*
 * This abstract data typed double linked node is indented for double linked listed operations.
 */
#ifndef _DOUBLYLINKEDNODE_H
#define _DOUBLYLINKEDNODE_H

#include <cstddef>

template < typename item_type >
struct doublylinkednode
{
  typedef doublylinkednode * link;

  link next;
  link prev;
  item_type data;

  doublylinkednode (item_type data, link next, link prev)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }

  doublylinkednode (item_type data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }

  doublylinkednode ()
  {
    next = NULL;
    prev = NULL;
  }

};

#endif
