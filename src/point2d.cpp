#include "point2d.h"

std::ostream& operator<<(std::ostream& out, const Point2D& point) {
    // Вывод точки
    out << "(" << point._x << ", " << point._y << ")";
    return out;
}
std::istream& operator>>(std::istream& in, Point2D& point) {
    // Ввод точки
    in >> point._x >> point._y;
    return in;
}

bool operator==(const Point2D& a, const Point2D& b) {
    return ( (a._x == b._x) && (a._y == b._y) );
}
// bool operator<(const Point2D& a, const Point2D& b) {
//     return (a.x() * a.x() + a.y() * a.y()) < (b.x() * b.x() + b.y() * b.y());
// }