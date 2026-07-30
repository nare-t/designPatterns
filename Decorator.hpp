#pragma once
#include <string>

namespace Decorator {

class Coffee {
  public:
    virtual ~Coffee() {};
    virtual std::string print() = 0;
};

class SimpleCoffee : public Coffee {
  public:
    std::string print() override { return "simple coffee"; }
};

class MilkDecorator : public Coffee {
  private:
    Coffee *coffee;

  public:
    MilkDecorator(Coffee *c) { coffee = c; }
    std::string print() override { return coffee->print() + " + milk"; }
};

class SugarDecorator : public Coffee {
  private:
    Coffee *coffee;

  public:
    SugarDecorator(Coffee *c) { coffee = c; }
    std::string print() override { return coffee->print() + " + sugar"; }
};
} // namespace Decorator
