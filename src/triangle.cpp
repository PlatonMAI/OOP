#pragma once
#include <triangle.h>
#include <../src/triangleValidator.cpp>

template <Number T>
Triangle<T>::Triangle(std::vector<Point2D<T>>& points) {
    this->constructor(points);
}
template <Number T>
Triangle<T>::Triangle(const Triangle& other) {
    std::cout << "Конструктор копирования треугольника" << std::endl;
    std::vector<Point2D<T>> points = other.getPoints();

    this->constructor(points);
}

template <Number T>
Triangle<T>& Triangle<T>::operator=(const Triangle& other) {
    std::cout << "Оператор копирующего присваивания треугольника " << std::endl;
    std::vector<Point2D<T>> points = other.getPoints();

    this->builder(points);

    return *this;
}

template <Number T>
Point2D<T> Triangle<T>::get_center() {
    // Геометрический центр треугольника - точка пересечения медиан
    // Так как все медианы треугольника пересекаются в одной точке, достаточно рассмотреть две

    // Прямую, на которой лежит медиана, можно определить двумя точками - 
    // вершиной и серединой противолежащей стороны

    Point2D<T>
    start1 = this->_array[0],
    start2 = this->_array[1],
    end1 = Point2D<T>( (this->_array[1].x() + this->_array[2].x()) / 2, (this->_array[1].y() + this->_array[2].y()) / 2 ),
    end2 = Point2D<T>( (this->_array[0].x() + this->_array[2].x()) / 2, (this->_array[0].y() + this->_array[2].y()) / 2 );

    return getIntersectionPoint<T>(start1, end1, start2, end2);
}
template <Number T>
Triangle<T>::operator double() {
    Vector<T>
    a(this->_array[0], this->_array[1]),
    b(this->_array[0], this->_array[2]);

    double cos = getCos(a, b);

    return 0.5 * a * b * (1 - cos * cos);
}

template <Number T>
bool operator==(Triangle<T>& a, Triangle<T>& b) {
    // Треугольники равны, если равны все их стороны
    std::vector<double>
    sides1(3),
    sides2(3);
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            sides1.push_back( Vector<T>( a._array[i], a._array[j] ).getLength() );
            sides2.push_back( Vector<T>( b._array[i], b._array[j] ).getLength() );
        }
    }

    sort(sides1.begin(), sides1.end());
    sort(sides2.begin(), sides2.end());

    for (int i = 0; i < 3; ++i) {
        if (sides1[i] != sides2[i])
            return false;
    }

    return true;
}

template <Number T>
Triangle<T> Triangle<T>::create(std::vector<Point2D<T>> points) {
    TriangleValidator<T> validator;

    validator.validate(points);

    return Triangle(points);
}