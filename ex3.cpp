#include <cstddef>
#include <iostream>

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

  void push (int data)
  {
    Node *newnode = new Node (data);
    newnode->next = head;
    head = newnode;
  }

  void print ()
  {
    Node *iter = head;
    while (iter) {
      std::cout << iter->val << std::endl;
      iter = iter->next;
    }
  }
};

void
print (Node * a)
{
  Node *iter = a;
  while (iter) {
    std::cout << iter->val << " ";
    iter = iter->next;
  }
  std::cout << std::endl;
}

int
main ()
{
  Node *newnode = new Node ();

  LinkedList a, b;
  a.push (1);
  a.push (2);
  a.push (2);
  a.print ();

  LinkedList c;
  add (a.head, b.head);

  return 0;
}
