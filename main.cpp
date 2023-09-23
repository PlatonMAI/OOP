#include <bits/stdc++.h>
// #include <iostream>

#include "lib.h"

using namespace std;

int main() {
    cout << "Введите два ненулевых целых числа: " << endl;
    int num1, num2;
    cin >> num1 >> num2;

    int res = tryGCD(num1, num2);
    if (res != -1) {
        cout << "НОД: " << res << endl;
    }
}