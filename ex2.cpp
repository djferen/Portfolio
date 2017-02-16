
#include <iostream>

struct Node
{
  Node *next;
  Node *prev;
  int data;

  Node ()
  {
    next = 0;
    prev = 0;
    data = 0;
  }
};

struct FIFO
{
  Node *h;
  Node *t;

  FIFO ()
  {
    h = 0;
    t = 0;
  }

  void append (int data)
  {
    Node *newnode = new Node ();
    newnode->data = data;
    newnode->prev = t;
    if (t) {
      t->next = newnode;
    }
    t = newnode;
  }

  void enqueue (int *list, int length)
  {
    for (int i = 0; i < length; i++) {
      enqueue (list[i]);
    }
  }

  void enqueue (int data)
  {
    Node *newnode = new Node ();
    newnode->data = data;
    newnode->next = h;
    if (h)
      h->prev = newnode;
    h = newnode;
    if (!t)
      t = newnode;
  }

  bool dequeue (int *data)
  {
    if (t != 0) {
      *data = t->data;
      Node *temp = t;
      t = t->prev;
      if (t)
	t->next = 0;
      delete temp;
      return true;
    }
    return false;
  }

  bool find (int target)
  {
    Node *node = h;
    while (node != 0) {
      if (node->data == target)
	return true;
      node = node->next;
    }
    return false;
  }
};

int
main ()
{
  FIFO myfifo;

  myfifo.enqueue (10);
  myfifo.enqueue (20);
  myfifo.enqueue (30);
  myfifo.enqueue (40);
  myfifo.enqueue (50);
  myfifo.append (0);
  myfifo.append (5);

  int mylist[3] = { 100, 200, 300 };
  myfifo.enqueue (mylist, 3);

  if (myfifo.find (30))
    std::cout << "Found 30" << std::endl;

  int temp;
  while (myfifo.dequeue (&temp)) {
    std::cout << "dequeue returned " << temp << std::endl;
  }

  return 0;
}
