#include <vector.h>

Vector::Vector(Point2D& a, Point2D& b) {
    _x = b.x() - a.x();
    _y = b.y() - a.y();
}

double Vector::getLength() {
    return sqrt(_x * _x + _y * _y);
}
Vector::operator double() {
    return this->getLength();
}

double scalar(Vector& a, Vector& b) {
    return (a.x() * b.x() + a.y() * b.y());
}
double getCos(Vector& a, Vector& b) {
    return scalar(a, b) / (a * b);
}