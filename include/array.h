#pragma once

#include <../src/figure.cpp>

template <Number T>
class Array {
    typedef std::vector<Figure<T>*> array;

public:
    Array(const array& figures) : figures(figures) {}

    void printFigures();
    double getTotalSquare();
    void popIndex(int);

private:
    array figures;
};