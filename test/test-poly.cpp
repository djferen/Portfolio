#include "poly.h"
#include <iostream>
using namespace std;

int main() {
  User *ptrUser = new User();
  ptrUser->Action();
  delete ptrUser;

  User user;
  user.Action();

  Base * base = new Derived1;
  base->DisplayAction();

  B *b = new D;
}