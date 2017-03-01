#include <cstddef>
#include <sstream>
#include <iostream>
#include <string>

struct Node
{
  int val;
  Node *next;

  Node (int x):val (x), next (NULL)
  {
  }

  Node ():val (0), next (NULL)
  {
  }
};

struct LinkedList
{
  Node *head;

  LinkedList ()
  {
    head = NULL;
  }

  bool empty()
  {
     return head == NULL;
  }

  void push(int val)
  {
    Node *newnode = new Node (val);
    newnode->next = head;
    head = newnode;
  }

  bool pop(int & val)
  {
    if(head)
    {
      val = head->val;
      Node * tmp = head;
      head = head->next;
      delete tmp;
      return true;
    }
    return false;
  }

  bool contains(int val)
  {
    Node * tmp = head;
    while(tmp != NULL)
    {
       if(tmp->val == val)
          return true;
       tmp = tmp->next;
    }
    return false;
  }

  void replace(int from, int to)
  {
    Node * tmp = head;
    while(tmp != NULL)
    {
       if(tmp->val == from)
          tmp->val = to;
       tmp = tmp->next;
    }
  }

  std::string intToString (int a)
  {
    std::ostringstream temp;
    temp<<a;
    return temp.str();
  }

  std::string toString()
  {
    std::string result;
    Node *iter = head;
    while (iter) {
      result += intToString(iter->val);
      iter = iter->next;
    }
    return result;
  }
};

int
main ()
{
  LinkedList a, b;
  a.push (1);
  a.push (2);
  a.push (2);

  std::cout << "List: " << a.toString() << std::endl;

  a.replace(1,2);

  std::cout << "List: " << a.toString() << std::endl;
 
  int val;
  a.pop(val);
  a.pop(val);
  a.pop(val);
  a.pop(val);
  a.pop(val);

  std::cout << "List: " << a.toString() << std::endl;

  return 0;
}
