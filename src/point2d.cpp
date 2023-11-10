#pragma once
#include "point2d.h"

template <Number T>
std::ostream& operator<<(std::ostream& out, const Point2D<T>& point) {
    // Вывод точки
    out << "(" << point._x << ", " << point._y << ")";
    return out;
}
template <Number T>
std::istream& operator>>(std::istream& in, Point2D<T>& point) {
    // Ввод точки
    in >> point._x >> point._y;
    return in;
}

template <Number T>
bool operator==(const Point2D<T>& a, const Point2D<T>& b) {
    return ( (a._x == b._x) && (a._y == b._y) );
}
// bool operator<(const Point2D& a, const Point2D& b) {
//     return (a.x() * a.x() + a.y() * a.y()) < (b.x() * b.x() + b.y() * b.y());
// }