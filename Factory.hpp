#pragma once

#include <iostream>

class Coffee {
  public:
    virtual void brew() = 0;
    virtual ~Coffee() {};
};

class Latte : public Coffee {
  public:
    void brew() { std::cout << "brewing latte"; }
};

class ArmenianCoffee : public Coffee {
  public:
    void brew() { std::cout << "\nbrewing strong armenian dark coffee"; }
};

class CoffeeFactory {
  public:
    Coffee *createCoffee(int whichCoffee) {
        if (whichCoffee == 1) {
            return new Latte();
        }
        if (whichCoffee == 2) {
            return new ArmenianCoffee();
        }
        return nullptr;
    }
};
