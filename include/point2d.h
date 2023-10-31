#pragma once
#include <iostream>

class Point2D {
    friend std::ostream& operator<<(std::ostream&, const Point2D&);
    friend std::istream& operator>>(std::istream&, Point2D&);
    
    friend bool operator==(const Point2D&, const Point2D&);
    // friend bool operator<(const Point2D&, const Point2D&);
public:
    Point2D() = default;
    Point2D(double x, double y) : _x(x), _y(y) {}

    double x() const { return _x; }
    double y() const { return _y; }

    double& x() { return _x; }
    double& y() { return _y; }

protected:
    double _x;
    double _y;
};