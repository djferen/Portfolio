/*
 * This abstract data typed double linked node is indented for double linked listed operations.
 */
#ifndef _DOUBLYLINKEDNODE_H
#define _DOUBLYLINKEDNODE_H

#include <cstddef>

template < class item > struct doublylinkednode
{
  typedef doublylinkednode *link;

  link next;
  link prev;
  item data;

    doublylinkednode (item data, link next, link prev)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }

  doublylinkednode (item data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }

  doublylinkednode () {
    next = NULL;
    prev = NULL;
  }
};

#endif
