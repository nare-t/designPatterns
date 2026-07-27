#include "Factory.hpp"
#include "Singleton.hpp"
#include <iostream>
using namespace std;

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mutex;

void testSingleton() {
    Singleton *firstObject = Singleton::getInstance();
    Singleton *secondObject = Singleton::getInstance();

    if (firstObject == secondObject) {
        cout << "both point to the same object" << endl;
    } else {
        cout << "singleton pattern does not work properly" << endl;
    }
}

void testFactory() {
    CoffeeFactory factory;
    Coffee *coffee1 = factory.createCoffee(1);
    Coffee *coffee2 = factory.createCoffee(2);
    coffee1->brew();
    coffee2->brew();
    delete coffee1;
    delete coffee2;
}

int main() {
    cout << "\nTESTING SINGLETON\n";
    testSingleton();

    cout << "\nTESTING FACTORY\n";
    testFactory();
    return 0;
}
