#include "Adapter.hpp"
#include "Builder.hpp"
#include "Decorator.hpp"
#include "Factory.hpp"
#include "Observer.hpp"
#include "Singleton.hpp"
#include "Strategy.hpp"
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

void testDecorator() {
    Decorator::Coffee *newCoffee = new Decorator::SimpleCoffee();
    newCoffee = new Decorator::MilkDecorator(newCoffee);
    newCoffee = new Decorator::MilkDecorator(newCoffee);
    newCoffee = new Decorator::SugarDecorator(newCoffee);
    cout << newCoffee->print();
    delete newCoffee;
}
void testAdapter() {
    SecondInterface *metersProvider = new SecondInterface();
    cout << "\nSecondInterface output: " << metersProvider->getMeters();
    FirstInterface *adapter = new Adapter(metersProvider);
    cout << "\nAdapter converted output: " << adapter->getKilometers();
    delete metersProvider;
    delete adapter;
}
void testBuilder() {
    CarBuilder builder;
    builder.BuildEngine();
    builder.BuildSeats();
    Car *newCar = builder.GetCar();
    newCar->DisplayCar();
    delete newCar;

    CarBuilder builder_2;
    builder_2.BuildSeats();
    Car *secondCar = builder_2.GetCar();
    secondCar->DisplayCar();
    delete secondCar;
}
void testObserver() {
    Newspaper newspaper;
    Reader reader1("Nare");
    Reader reader2("Ani");
    Reader reader3("Hayk");
    newspaper.subscribe(&reader1);
    newspaper.subscribe(&reader2);
    newspaper.subscribe(&reader3);
    newspaper.publishNews("First news");
    cout << "Ani left\n";
    newspaper.unsubscribe(&reader2);
    newspaper.publishNews("Second news");
}
void testStrategy() {
    Navigator gps;
    CarStrategy carPath;
    WalkingStrategy walkingPath;
    gps.setStrategy(&carPath);
    gps.buildRoute("Yerevan", "Sevan");
    gps.setStrategy(&walkingPath);
    gps.buildRoute("Yerevan", "Sevan");
}

int main() {
    cout << "\nTESTING SINGLETON\n";
    testSingleton();

    cout << "\nTESTING FACTORY\n";
    testFactory();

    cout << "\nTESTING DECORATOR\n";
    testDecorator();

    cout << "\n\nTESTING ADAPTER";
    testAdapter();

    cout << "\n\nTESTING BUILDER\n";
    testBuilder();

    cout << "\n\nTESTING OBSERVER\n";
    testObserver();

    cout << "\n\nTESTING STRATEGY\n";
    testStrategy();

    return 0;
}
