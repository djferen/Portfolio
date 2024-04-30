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
  D *d = dynamic_cast<D *>(b);
  if (d != NULL)
    cout << "works";
  else
    cout << "cannot cast B* to D*";
}