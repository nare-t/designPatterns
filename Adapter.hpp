#pragma once

class FirstInterface {
  public:
    virtual ~FirstInterface() {}
    virtual double getKilometers() = 0;
};

class SecondInterface {
  public:
    double getMeters() { return 5000; }
};

class Adapter : public FirstInterface {
  private:
    SecondInterface *second;

  public:
    Adapter(SecondInterface *s) { second = s; }
    double getKilometers() { return second->getMeters() / 1000; }
};
