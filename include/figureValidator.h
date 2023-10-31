#pragma once

#include <figure.h>
#include <validatorError.h>

class FigureValidator {
public:
    virtual bool validate(std::vector<Point2D>&) = 0;
};