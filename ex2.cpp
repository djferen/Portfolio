
#include <iostream>

struct Node {
  Node * next;
  int data;
  Node()
  {
    next = 0;
    data = 0;
  }
};

struct FIFO {
  Node * fi;
  Node * fo; 
  FIFO()
  {
     fi = 0;
     fo = 0;
  }

  void enqueue(int data)
  {
     Node * newnode = new Node();
     newnode->data = data;
     if(fi)
       fi->next = newnode;
     fi = newnode;
     if(!fo)
       fo = newnode;
  }

  bool dequeue(int * data)
  {
     if (fo != 0)
     {
       *data = fo->data; 
       Node * temp = fo;
       fo = fo->next;
       delete temp; 
       return true;
     }
     return false;
  }

  bool find(int target)
  {
     Node * node = fo;
     while(node != 0)
     {
       if(node->data == target)
           return true;
       node = node->next;
     }
     return false;
  }
}; 

int main()
{
  FIFO myfifo;

  myfifo.enqueue(10);
  myfifo.enqueue(20);
  myfifo.enqueue(30);
  myfifo.enqueue(40);
  myfifo.enqueue(50);

  if (myfifo.find(30))
     std::cout << "Found 30" << std::endl;

  int temp;
  while(myfifo.dequeue(&temp))
  {
    std::cout << "dequeue returned " << temp << std::endl;
  }

  return 0;
}

