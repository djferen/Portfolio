#include "poly.h"
#include <iostream>
using namespace std;

int main() {
  User *ptrUser = new User();
  ptrUser->Action();
  delete ptrUser;

  Base *base1 = new Derived1;
  base1->DisplayAction();

  Base *base2 = new Derived2;
  base2->DisplayAction();

  delete base1;
  delete base2;

  cout << "App: Launched with the ConcreteCreator1.\n";
  Creator *creator1 = new ConcreteCreator1();
  ClientCode(*creator1);
  Product *product1 = creator1->FactoryMethod();
  cout << endl << product1->Operation() << endl;

  cout << endl << "App: Launched with the ConcreteCreator2.\n";
  Creator *creator2 = new ConcreteCreator2();
  ClientCode(*creator2);
  Product *product2 = creator2->FactoryMethod();
  cout << endl << product2->Operation() << endl;

  delete creator1;
  delete creator2;
  delete product1;
  delete product2;
}