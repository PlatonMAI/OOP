#pragma once

#include <../src/figure.cpp>
#include <validatorError.h>

template <Number T>
class FigureValidator {
public:
    virtual bool validate(std::vector<Point2D<T>>&) = 0;
};