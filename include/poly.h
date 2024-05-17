
#include <iostream>
using namespace std;

// An interface
class Base {
public:
  Base() {}

  virtual ~Base() {}
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

class Product {
public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct1}";
  }
};
class ConcreteProduct2 : public Product {
public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct2}";
  }
};

class Creator {
public:
  virtual ~Creator(){};
  virtual Product *FactoryMethod() const = 0;
  std::string SomeOperation() const {
    Product *product = this->FactoryMethod();
    std::string result =
        "Creator: The same creator's code has just worked with " +
        product->Operation();
    delete product;
    return result;
  }
};

class ConcreteCreator1 : public Creator {
public:
  Product *FactoryMethod() const override { return new ConcreteProduct1(); }
};

class ConcreteCreator2 : public Creator {
public:
  Product *FactoryMethod() const override { return new ConcreteProduct2(); }
};

void ClientCode(const Creator &creator) {
  std::cout
      << "Client: I'm not aware of the creator's class, but it still works.\n"
      << creator.SomeOperation() << std::endl;
}
