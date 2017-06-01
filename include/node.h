/*
 * This abstract data type node class provides a definition for a node capable of being used
 * in a linked list.
 */
#ifndef _NODE_H
#define _NODE_H

template < typename item_type >
struct node
{

  typedef node * link;

  link next;
  item_type data;

  node (item_type data, link next)
  {
    this->data = data;
    this->next = next;
  }

  node (item_type data)
  {
    this->data = data;
    next = nullptr;
  }

  node ()
  {
    next = nullptr;
  }
};

#endif
