#pragma once
#include <array.h>

template <Number T>
void Array<T>::printFigures() {
    for (Figure<T>* figure : this->figures) {
        std::cout << *figure;
        std::cout << "Геометрический центр: " << figure->get_center() <<
        "\nПлощадь: " << double(*figure) << std::endl;
    }
}

template <Number T>
double Array<T>::getTotalSquare() {
    double res = 0;
    for (Figure<T>* figure : this->figures) {
        res += double(*figure);
    }

    return res;
}

template <Number T>
void Array<T>::popIndex(int index) {
    if (index >= this->figures.size()) {
        throw std::logic_error("Index out of range");
    }

    this->figures.erase(this->figures.begin() + index);
}