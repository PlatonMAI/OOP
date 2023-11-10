#pragma once
#include <vector.h>

template <Number T>
Vector<T>::Vector(Point2D<T>& a, Point2D<T>& b) {
    this->_x = b.x() - a.x();
    this->_y = b.y() - a.y();
}

template <Number T>
double Vector<T>::getLength() {
    return sqrt(this->_x * this->_x + this->_y * this->_y);
}
template <Number T>
Vector<T>::operator double() {
    return this->getLength();
}

template <Number T>
double scalar(Vector<T>& a, Vector<T>& b) {
    return (a.x() * b.x() + a.y() * b.y());
}
template <Number T>
double getCos(Vector<T>& a, Vector<T>& b) {
    return scalar(a, b) / (a * b);
}