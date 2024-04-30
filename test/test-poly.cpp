#include "poly.h"
#include <iostream>
using namespace std;

int main() {
  User *ptrUser = new User();
  ptrUser->Action();
  delete ptrUser;

  Base * base = new Derived1;
  base->DisplayAction();

  B *b = new D;
  b->Display();
  b->Action();

  cout << "App: Launched with the ConcreteCreator1.\n";
  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);
  cout << endl << "App: Launched with the ConcreteCreator2.\n";
  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;  
}