#pragma once

#include <iostream>

class TV {
  public:
    void turnOn() { std::cout << "TV is on\n"; }
};

class Audio {
  public:
    void turnOn() { std::cout << "audio is on\n"; }
    void setVolume(int volumeLevel) { std::cout << "audio volume " << volumeLevel << "\n"; }
};

class MovieFacade {
  private:
    TV tv;
    Audio audio;

  public:
    void watchMovie() {
        std::cout << "movie loading...\n";
        tv.turnOn();
        audio.turnOn();
        audio.setVolume(15);
        std::cout << "movie loaded";
    }
};