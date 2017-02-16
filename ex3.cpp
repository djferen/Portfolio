#include <cstddef>

struct Node {
     int val;
     Node *next;
     Node(int x) : val(x), next(NULL) {}
     Node(): val(0), next(NULL){}
 }; 


int main ()
{
  Node * newnode = new Node();

  return 0;
}




