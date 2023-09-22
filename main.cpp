#include <bits/stdc++.h>
// #include <iostream>

#include "lib.h"

using namespace std;

int main() {
    cout << "Введите два ненулевых целых числа: " << endl;
    int num1, num2;
    cin >> num1 >> num2;

    int res = GCD(num1, num2);

    if (res)
        cout << "НОД: " << res << endl;
    else
        cout << "Некорректные данные" << endl;
}