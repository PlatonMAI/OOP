#pragma once

#include <../src/rectangle.cpp>

template <Number T>
class Square : public Rectangle<T> {
public:
    using Rectangle<T>::Rectangle;

    virtual std::string getName() const override { return name; }

    static Square<T> create(std::vector<Point2D<T>>);
    static Square<T> create(Point2D<T>&, Point2D<T>&);
protected:
    static inline std::string name = "Квадрат";
};