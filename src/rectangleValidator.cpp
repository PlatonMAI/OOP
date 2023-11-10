#pragma once
#include <rectangleValidator.h>
#include <../src/rectangle.cpp>

template <Number T>
bool RectangleValidator<T>::validate(std::vector<Point2D<T>>& points) {
    // Должно быть четыре точки
    if (points.size() != 4) {
        throw validator_error("Некорректное число точек");
    }

    // Все углы должны быть прямые

    // Проверка на то, что все углы прямые, сводится к проверке ортогональности (через скалярное произведение)
    // двух пар векторов, образованных одной из двух противоположных точек и двух других точек.
    
    // Также важно учитывать, что нулевой вектор по определению ортогонален любому другому.
    // Поэтому нужно добавить дополнительную проверку, не совпадают ли точки между собой.

    std::vector<Point2D<T>> new_points = sortPoints<T>(points);
    for (int i = 0; i < 4; i += 2) {
        for (int j = 1; j < 4; j += 2) {
            if (new_points[i] == new_points[j]) {
                throw validator_error("Введенные точки не образуют прямоугольник:\nдве или более точек совпадают");
            }
        }

        Vector<T>
        a(new_points[i], new_points[1]),
        b(new_points[i], new_points[3]);

        double res = scalar<T>(a, b);

        if (res != 0)  {
            throw validator_error("Введенные точки не образуют прямоугольник:\nстороны не образуют прямые углы");
        }
    }

    return true;
}
template <Number T>
bool RectangleValidator<T>::validate(Point2D<T>& a, Point2D<T>& c) {
    // Когда мы не можем восстановить прямоугольник по двум точкам?
    // Когда эти точки лежат на одной прямой.
    // Когда две точки принадлежат одной гиперплоскости (в двумерном случае - прямой)?
    // Когда у них совпадает хотя бы одна координата.

    if ( (a.x() == c.x()) || (a.y() == c.y()) ) {
        throw validator_error("Введенные точки не образуют прямоугольник:\nони лежат на одной прямой");
    }

    return true;
}