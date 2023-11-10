#pragma once

#include <../src/figureValidator.cpp>

template <Number T>
class TriangleValidator : public FigureValidator<T> {
public:
    virtual bool validate(std::vector<Point2D<T>>&) override;
};