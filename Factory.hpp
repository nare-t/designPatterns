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

class CoffeeShop {
  public:
    virtual ~CoffeeShop() {};
    virtual Coffee *makeCoffee() = 0;

    void orderCoffee() {
        Coffee *coffee = makeCoffee();
        coffee->brew();
        delete coffee;
    }
};

class Cafe1 : public CoffeeShop {
  public:
    Coffee *makeCoffee() { return new Latte(); }
};

class Cafe2 : public CoffeeShop {
  public:
    Coffee *makeCoffee() { return new ArmenianCoffee(); }
};