#pragma once
#include <array.h>

template <Number T>
void Array<T>::printFigures() {
    // for (std::shared_ptr<Figure<T>>& figure : this->figures) {
    for (int i = 0; i < this->figures.size(); ++i) {
        std::cout << *(this->figures[i]);
        std::cout << "Геометрический центр: " << this->figures[i]->get_center() <<
        "\nПлощадь: " << double(*(this->figures[i])) << std::endl;
    }
}

template <Number T>
double Array<T>::getTotalSquare() {
    double res = 0;
    // for (std::shared_ptr<Figure<T>>& figure : this->figures) {
    for (int i = 0; i < this->figures.size(); ++i) {
        res += double(*(this->figures[i]));
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