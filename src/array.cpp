#include <array.h>

void printFigures(Array& array) {
    for (Figure* figure : array) {
        std::cout << *figure;
        std::cout << "Геометрический центр: " << figure->get_center() <<
        "\nПлощадь: " << double(*figure) << std::endl;
    }
}

double getTotalSquare(Array& array) {
    double res = 0;
    for (Figure* figure : array) {
        res += double(*figure);
    }

    return res;
}

Array& popIndex(Array& array, int index) {
    if (index >= array.size()) {
        throw std::logic_error("Index out of range");
    }

    array.erase(array.begin() + index);

    return array;
}