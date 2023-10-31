#pragma once
#include <cmath>

#include <point2d.h>

class Vector : public Point2D {
public:
    using Point2D::Point2D;
    Vector(Point2D&, Point2D&);

    double getLength();
    operator double();
};

// Скалярное произведение векторов
double scalar(Vector&, Vector&);

// Косинус угла между векторами
double getCos(Vector&, Vector&);