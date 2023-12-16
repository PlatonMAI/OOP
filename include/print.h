#pragma once

#include <mutex>
#include <sstream>

struct print : std::stringstream {
    std::mutex* print_mutex;

    print(std::mutex* _mutex) : print_mutex(_mutex) {}

    ~print() {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(*print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};