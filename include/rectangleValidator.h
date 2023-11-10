#pragma once

#include <../src/figureValidator.cpp>

template <Number T>
class RectangleValidator : public FigureValidator<T> {
public:
    virtual bool validate(std::vector<Point2D<T>>&) override;
    virtual bool validate(Point2D<T>&, Point2D<T>&);
};