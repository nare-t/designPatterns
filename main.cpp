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
    CoffeeShop *shop1 = new Cafe1();
    shop1->orderCoffee();
    delete shop1;

    CoffeeShop *shop2 = new Cafe2();
    shop2->orderCoffee();
    delete shop2;
}

int main() {
    cout << "\nTESTING SINGLETON\n";
    testSingleton();

    cout << "\nTESTING FACTORY\n";
    testFactory();
    return 0;
}
