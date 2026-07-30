#pragma once
#include <iostream>
#include <string>

class Car {
  public:
    std::string engine = "No Engine";
    int seats = 0;

    void DisplayCar() const {
        std::cout << "Engine: " << engine << "\n";
        std::cout << "Seats : " << seats << "\n";
    }
};

class CarBuilder {
  private:
    Car *car;

  public:
    CarBuilder() { car = new Car(); }

    void BuildEngine() { car->engine = "Sports Engine"; }

    void BuildSeats() { car->seats = 2; }

    Car *GetCar() { return car; }
};