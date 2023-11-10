#pragma once
#include <memory>

#include <../src/figure.cpp>

template <Number T>
class Array {
    typedef std::vector<std::shared_ptr<Figure<T>>> array;

public:
    Array(const array& figures) : figures(figures) {}

    void printFigures();
    double getTotalSquare();
    void popIndex(int);

private:
    array figures;
};