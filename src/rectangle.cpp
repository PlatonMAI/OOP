#pragma once
#include <rectangle.h>
#include <../src/rectangleValidator.cpp>

template <Number T>
std::vector<Point2D<T>> recoverPoints(Point2D<T>& a, Point2D<T>& c) {
    Point2D
    b(a.x(), c.y()),
    d(c.x(), a.y());

    return std::vector<Point2D<T>>{a, b, c, d};
}

template <Number T>
// Хотим, чтобы первая и третья, а также вторая и четвертая точки в массиве были противоположными вершинами
std::vector<Point2D<T>> sortPoints(std::vector<Point2D<T>>& points) {
    // Для этого зафиксируем точку, найдем расстояния от нее до всех остальных трех.
    // Точка, до которой будет наибольшее расстояние - и есть искомая противоположная вершина
    
    std::vector<Point2D<T>> new_points(4);
    new_points[0] = points[0];
    double max_dist = 0;
    int index = -1;
    for (int i = 0; i < 3; ++i) {
        double dist = Vector(points[0], points[i + 1]).getLength();

        if (dist > max_dist) {
            max_dist = dist;
            index = i + 1;
        }
    }

    new_points[2] = points[index];
    new_points[1] = points[ (index - 1) == 0 ? 3 : (index - 1) ];
    new_points[3] = points[ (index + 1) == 4 ? 1 : (index + 1) ];

    // std::cout << "Посортил: ";
    // for (int i = 0; i < 4; ++i)
    //     std::cout << new_points[i] << " ";
    // std::cout << std::endl;

    return new_points;
}

template <Number T>
Rectangle<T>::Rectangle(std::vector<Point2D<T>>& points) {
    points = sortPoints<T>(points);

    // Можно ли как-то вызвать конструктор Figure с отсортированным points?
    this->constructor(points);
}
template <Number T>
Rectangle<T>::Rectangle(Point2D<T>& a, Point2D<T>& c) {
    std::vector<Point2D<T>> tmp( recoverPoints<T>(a, c) );
    // Тут, очевидно, мы гарантируем, что вектор отсортирован правильно
    this->constructor(tmp);
}
template <Number T>
Rectangle<T>::Rectangle(const Rectangle& other) {
    std::cout << "Конструктор копирования прямоугольника" << std::endl;
    std::vector<Point2D<T>> points = other.getPoints();

    this->constructor(points);
}

template <Number T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    std::cout << "Оператор копирующего присваивания прямоугольника " << std::endl;
    std::vector<Point2D<T>> points = other.getPoints();

    this->builder(points);

    return *this;
}

template <Number T>
Point2D<T> Rectangle<T>::get_center() {
    // Центр прямоугольника - точка пересечения его диагоналей
    // По построению - первая и третья, а также вторая и четвертая точки - противоположные вершины

    return getIntersectionPoint(this->_array[0], this->_array[2], this->_array[1], this->_array[3]);
}
template <Number T>
Rectangle<T>::operator double() {
    // Площадь - приятно
    Vector<T>
    a(this->_array[0], this->_array[1]),
    b(this->_array[0], this->_array[3]);

    return a * b;
}

template <Number T>
Rectangle<T> Rectangle<T>::create(std::vector<Point2D<T>> points) {
    RectangleValidator<T> validator;

    validator.validate(points);

    return Rectangle(points);
}
template <Number T>
Rectangle<T> Rectangle<T>::create(Point2D<T>& a, Point2D<T>& c) {
    RectangleValidator<T> validator;

    validator.validate(a, c);

    return Rectangle(a, c);
}