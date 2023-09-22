// Copyright 2023 SomeName
#include <bits/stdc++.h>
#include "lib.h"

int GCD(int num1, int num2) {
    // Если какое-либо из чисел ноль, то считать не будем блин
    if (num1 * num2 == 0)
        return 0;

    while (num2 != 0) {
        // Пусть num1 - большее из чисел
        if (abs(num2) > abs(num1))
            std::swap(num1, num2);

        num1 = num1 % num2;
        std::swap(num1, num2);
    }

    return abs(num1);
}
