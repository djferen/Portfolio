#include "poly.h"
#include <iostream>
using namespace std;

int main() {
  User *ptrUser = new User();
  ptrUser->Action();
  delete ptrUser;

  ptrUser = User::CreateUser(1);
  ptrUser->Action();

  Base * base = new Derived1;
  base->DisplayAction();

  B *b = new D;
  b->Display();
  b->Action();
}