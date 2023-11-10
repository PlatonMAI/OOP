#pragma once

#include <../src/rectangleValidator.cpp>

template <Number T>
class SquareValidator : public RectangleValidator<T> {
public:
    virtual bool validate(std::vector<Point2D<T>>&) override;
    virtual bool validate(Point2D<T>&, Point2D<T>&) override;
};