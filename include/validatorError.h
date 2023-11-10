#pragma once
#include <string>

class validator_error: public std::exception {
public:
    validator_error(const std::string& message): message{message} {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};