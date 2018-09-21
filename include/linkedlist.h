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

  ~linkedlist()
  {
	  linktype iter = head;
	  linktype last = head;

	  while(iter)
	  {
		  iter = iter->next;

		  std::cout << "deleting: " << last << std::endl;

		  delete last;

		  last = iter;
	  }
  }

  linkedlist(const linkedlist & ll) : head(nullptr)
  {
	  linktype temp = nullptr, citer = ll.head, iter = ll.head;
	  bool first = true;

	  while(iter)
	  {
		  if(head == nullptr)
		  {
			   head = new node<item_type> (iter->data);
			   citer = head;
		  }
		  else
		  {
			  temp = new node<item_type> (iter->data);
			  citer->next = temp;
			  citer = temp;
		  }
		  iter = iter->next;
	  }
  }

  linkedlist(linkedlist && ll)
  {
	 std::cout << "Running move constructor..." << std::endl;

	 head = ll.head;
	 ll.head = nullptr;

	 std::cout << "Exiting\n";
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


  bool containsCycle()
  {
	  linktype fast = head, slow = head;

	  if(fast && fast->next && fast == fast->next)
	  {
		  return true;
	  }

	  while(fast && fast->next && fast->next->next)
	  {
		  fast = fast->next->next;

		  if(fast == slow)
		  {
			  return true;
		  }

		  slow = slow->next;
	  }

	  return false;
  }

  linktype getLink(item_type item)
  {
	  linktype  iter = head;

	  while(iter)
	  {
		  if(iter->data == item)
		  {
			  return iter;
		  }
		  iter = iter->next;
	  }

	  return nullptr;
  }

  linktype getTailNode()
  {
	  linktype iter = head;
	  linktype tail = head;

	  while(iter)
	  {
		  iter = iter->next;

		  if(iter == nullptr)
		  {
			  return tail;
		  }

		  tail = iter;
	  }

	  return tail;
  }

  size_t getLength(void)
  {
	  size_t length = 0;
	  linktype iter = head;

	  while(iter)
	  {
		  length++;
		  iter = iter->next;
	  }

	  return length;
  }

private:

  linktype head;

};


#endif
