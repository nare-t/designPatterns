#pragma once

#pragma once
#include <iostream>
#include <string>

class RouteStrategy {
  public:
    virtual void buildRoute(std::string from, std::string to) = 0;
};

class CarStrategy : public RouteStrategy {
  public:
    void buildRoute(std::string from, std::string to) {
        std::cout << "car path: " << from << " - " << to << " takes 50 mins" << std::endl;
    }
};

class WalkingStrategy : public RouteStrategy {
  public:
    void buildRoute(std::string from, std::string to) {
        std::cout << "walking path: " << from << " - " << to << " takes 10 hours" << std::endl;
    }
};

class Navigator {
  private:
    RouteStrategy *strategy;

  public:
    void setStrategy(RouteStrategy *newStrategy) { strategy = newStrategy; }
    void buildRoute(std::string from, std::string to) { strategy->buildRoute(from, to); }
};