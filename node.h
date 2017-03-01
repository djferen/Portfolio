#ifndef _NODE_H
#define _NODE_H

#include <cstddef>

template <class item> 
struct node
{
  typedef node * link;

  link next;
  item data;

  node (item data, link next)
  {
    this->data = data;
    this->next = next;
  }

  node (item data)
  {
    this->data = data;
    next = NULL;
  }

  node ()
  {
    next = NULL;
  }
};

#endif
