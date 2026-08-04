#pragma once
#include <iostream>
#include <string>

class Car {
  public:
    std::string engine = "No Engine";
    int seats = 0;

    Car(std::string eng, int sts) : engine(eng), seats(sts) {}

    void DisplayCar() const {
        std::cout << "Engine: " << engine << "\n";
        std::cout << "Seats : " << seats << "\n";
    }
};

class CarBuilder {
  private:
    std::string engine = "";
    int seats = 0;

  public:
    CarBuilder() {}

    CarBuilder *setEngine(std::string engine) {
        this->engine = engine;
        return this;
    }

    CarBuilder *setSeats(int seats) {
        this->seats = seats;
        return this;
    }

    Car build() { return Car(this->engine, this->seats); }
};