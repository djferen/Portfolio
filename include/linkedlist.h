/*
 * This abstract data typed linked list is intended for linked listed operations.
 */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include <stack>

#include "node.h"

template < typename item_type >
struct linkedlist
{
  friend std::ostream & operator<< (std::ostream & output, const linkedlist<item_type> & ll)
  {
    linktype iter = ll.head;
    while(iter != nullptr)
    {
    	output << iter->data << ' ';
    	iter = iter->next;
    }
    return output;
  }

public:

  typedef typename node<item_type>::link linktype;

  linkedlist()
  {
    head = nullptr;
  }

  linkedlist(const item_type * items, int size) : head(nullptr)
  {
     linktype temp, iter;

     for(size_t i = 0; i < size; ++i)
     {
        if(head == nullptr)
        {
          head = new node<item_type> (items[i]);
          iter = head;
        }
        else
        {
          temp = new node<item_type> (items[i]);
          iter->next = temp;
          iter = temp;
        }
     }
  }

  void reverseByPtr()
  {
    linktype iter = head, save = nullptr, newhead = nullptr;

    while(iter != nullptr)
    {
      save = newhead;
      newhead = iter;
      iter = iter->next;
      newhead->next = save;
    }

    head = newhead;
  }

  void reverseByStack()
  {
    std::stack<linktype> rstack;

    linktype iter = head;

    while(iter != nullptr)
    {
      rstack.push(iter);
      iter = iter->next;
    }

    if(!rstack.empty())
    {
      head = rstack.top();
      head->next = nullptr;
      rstack.pop();
      iter = head;
    }

    while(!rstack.empty())
    {
      iter->next = rstack.top();
      rstack.pop();
      iter = iter->next;
      iter->next = nullptr;
    }
  }


private:

  linktype head;

};


#endif
