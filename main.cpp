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

int main() {

    testSingleton();

    return 0;
}
