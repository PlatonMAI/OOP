// Copyright 2023 Лебедько Платон
#include <bits/stdc++.h>
#include "lib.h"

int tryGCD(int num1, int num2) {
    try {
        return GCD(num1, num2);
    } catch(const std::logic_error& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
}

int GCD(int num1, int num2) {
    // Если какое-либо из чисел ноль, то считать не будем блин
    bool isValidData = isValid(num1, num2);

    if (!isValidData) {
        throw std::logic_error("НОД не определен для нулей!");
    }

    while (num2 != 0) {
        // Пусть num1 - большее из чисел
        if (abs(num2) > abs(num1))
            std::swap(num1, num2);

        num1 = num1 % num2;
        std::swap(num1, num2);
    }

    return abs(num1);
}

bool isValid(int num1, int num2) {
    return (num1 * num2 != 0);
}