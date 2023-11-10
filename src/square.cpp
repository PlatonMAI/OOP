#pragma once
#include <square.h>
#include <../src/squareValidator.cpp>

template <Number T>
Square<T> Square<T>::create(std::vector<Point2D<T>> points) {
    SquareValidator<T> validator;

    validator.validate(points);

    return Square(points);
}
template <Number T>
Square<T> Square<T>::create(Point2D<T>& a, Point2D<T>& c) {
    SquareValidator<T> validator;

    validator.validate(a, c);

    return Square(a, c);
}