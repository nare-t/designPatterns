#pragma once
#include <iostream>
#include <string>
#include <vector>

class Reader {
  private:
    std::string name;

  public:
    Reader(std::string readerName) { name = readerName; }
    void receiveNews(const std::string &news) {
        std::cout << name << " read: " << news << std::endl;
    }
};

class Newspaper {
  private:
    std::vector<Reader *> readers;

  public:
    void subscribe(Reader *r) {
        for (int i = 0; i < readers.size(); ++i) {
            if (readers[i] == r)
                return;
        }
        readers.push_back(r);
    }

    void unsubscribe(Reader *r) {
        for (int i = 0; i < readers.size(); i++) {
            if (readers[i] == r) {
                readers.erase(readers.begin() + i);
                break;
            }
        }
    }

    void publishNews(const std::string &news) {
        for (int i = 0; i < readers.size(); i++) {
            readers[i]->receiveNews(news);
        }
    }
};
