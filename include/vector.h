#pragma once
#include <cmath>

#include <../src/point2d.cpp>

template <Number T>
class Vector : public Point2D<T> {
public:
    using Point2D<T>::Point2D;
    Vector(Point2D<T>&, Point2D<T>&);

    double getLength();
    operator double();
};

// Скалярное произведение векторов
template <Number T>
double scalar(Vector<T>&, Vector<T>&);

// Косинус угла между векторами
template <Number T>
double getCos(Vector<T>&, Vector<T>&);