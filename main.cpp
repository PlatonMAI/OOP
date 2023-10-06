#include <bits/stdc++.h>
// #include <iostream>

#include "lib.h"

using namespace std;

int main() {
    try {
        const char* str = "902";
        Octal a(str);
    } catch (const std::logic_error& ex) {
        cout << "Уппс! Ошибка!" << endl;
        cout << ex.what() << endl;
    }

    Octal a("512");
    Octal b(512);

    Octal c(0);
    cout << c.size() << endl;
    cout << c << endl;

    try {
        a - b;
    } catch (const std::logic_error& ex) {
        cout << "Уппс! Ошибка!" << endl;
        cout << ex.what() << endl;
    }

    cout << b - a << endl;
    cout << b + a << endl;
    cout << a + b << endl;
    cout << a + a << endl;
    cout << a - a << endl;

    cout << Octal(182).toInt() << endl;
}