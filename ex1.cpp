
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

struct Stack {
  Node * head;
  Stack()
  {
    head = 0;
  }

  void push(int data)
  {
     Node * newnode = new Node();
     newnode->data = data;
     newnode->next = head;
     head = newnode;
  }

  bool pop(int * data)
  {
     if (head != 0)
     {
       *data = head->data; 
       Node * temp = head;
       head = head->next; 
       delete temp;
       return true;
     }
     return false;
  }

  bool find(int target)
  {
     Node * node = head;
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
  Stack mystack;

  mystack.push(10);
  mystack.push(20);
  mystack.push(30);
  mystack.push(40);
  mystack.push(50);

  if (mystack.find(30))
     std::cout << "Found 30" << std::endl;

  int temp;
  while(mystack.pop(&temp))
  {
    std::cout << "pop returned " << temp << std::endl;
  }

  return 0;
}

