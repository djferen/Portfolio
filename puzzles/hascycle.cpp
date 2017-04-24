
#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

bool has_cycle(Node* head) 
{
    map<Node *, int> cycle_map;
    
    Node * iter = head;
    while(iter != 0)
    {
        map<Node *, int>::iterator is_in_map = cycle_map.find(iter);
        if(is_in_map != cycle_map.end())
        {
            return true;   
        }
        else
        {
        	cycle_map.insert(std::pair<Node *, int>(iter, 1));
        }
        
        iter = iter->next;
    }
    return false;
}

int main ()
{
  Node * head = 0;

  cout << "0 " << (has_cycle(head) ? "true" : "false") << endl;

  head = new Node();
  head->next = 0;

  cout << "1 " << (has_cycle(head) ? "true" : "false") << endl;

  Node * another = new Node();
  another->next = 0;
  head->next = another;

  cout << "2 " << (has_cycle(head) ? "true" : "false") << endl;

  another->next = head;

  cout << "3 " << (has_cycle(head) ? "true" : "false") << endl;

  return 0;
}

