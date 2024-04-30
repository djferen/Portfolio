
#include <iostream>
using namespace std;

class Base {
public:
  Base() {}

  virtual // Ensures to invoke actual object destructor
      ~Base() {}

  // An interface
  virtual void DisplayAction() = 0;
};

class Derived1 : public Base {
public:
  Derived1() { cout << "Derived1 created" << endl; }

  ~Derived1() { cout << "Derived1 destroyed" << endl; }

  void DisplayAction() { cout << "Action from Derived1" << endl; }
};

class Derived2 : public Base {
public:
  Derived2() { cout << "Derived2 created" << endl; }

  ~Derived2() { cout << "Derived2 destroyed" << endl; }

  void DisplayAction() { cout << "Action from Derived2" << endl; }
};

class User {
public:
  // Creates Derived1 or Derived2 based on input
  User() : pBase(nullptr) {
    int input = 1;
    if (input == 1) {
      pBase = new Derived1;
    } else {
      pBase = new Derived2;
    }
  }

  ~User() {
    if (pBase) {
      delete pBase;
      pBase = nullptr;
    }
  }

  // Delegates to actual object
  void Action() { pBase->DisplayAction(); }

private:
  Base *pBase;
};

class B {
  virtual // Ensures to invoke actual object destructor
      ~Base() {}
  // An interface
  virtual void Display() = 0;
  virtual void Action() = 0;  
};
class D : public B {
  void Display() {}
  void Action() {}
};
