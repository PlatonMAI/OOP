#include <bits/stdc++.h>
// #include <iostream>

#include "lib.h"

using namespace std;

int main() {
    Octal octal("514");
    cout << octal << endl;

    Octal octal1 = octal;
    cout << octal1 << endl;

    Octal octal2(move(octal));
    cout << octal2 << endl;
    cout << octal << endl;

    Octal octal3 = move(octal2);
    cout << octal3 << endl;
    cout << octal2 << endl;

    Octal oct(514);
    cout << (octal3 < oct) << endl;
    cout << (octal3 > oct) << endl;
    cout << (octal3 == oct) << endl;

    Octal oct1("514");
    cout << (octal3 < oct1) << endl;
    cout << (octal3 > oct1) << endl;
    cout << (octal3 == oct1) << endl;

    oct1 = oct;
    cout << oct1 << endl;
    cout << oct << endl;

    oct1 = move(octal3);
    cout << oct1 << endl;
    cout << octal3 << endl;
}