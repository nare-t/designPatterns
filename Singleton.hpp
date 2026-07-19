#pragma once
#include <mutex>

class Singleton {
  private:
    static Singleton *instance;
    Singleton() {}

    static std::mutex mutex;

  public:
    static Singleton *getInstance() {
        // next line protects us from multithreading problem
        std::lock_guard<std::mutex> lock(mutex);

        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    /* these two lines ensure that the Singleton object
    cannot be copied or assigned to another object
    1st one is for copy constructor
    2nd one is for copy assignment operator
    */

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};
