#pragma once
#include <triangleValidator.h>

template <Number T>
bool TriangleValidator<T>::validate(std::vector<Point2D<T>>& points) {
    // Должно быть три точки
    if (points.size() != 3) {
        throw validator_error("Некорректное число точек");
    }

    // Треугольник можно построить на любых трех точках
    // Лишь бы не совпадали и на одной прямой не лежали
    // y1 = k*x1 + b
    // y2 = k*x2 + b
    // y3 = k*x2 + b
    // -> (y2-y1) = k*(x2-x1)
    // -> (y3-y1) = k*(x3-x1)
    // -> (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (points[i] == points[j]) {
                throw validator_error("Введенные точки не образуют треугольник:\nдве или более точек совпадают");
            }
        }
    }

    T
    k1 = (points[1].y() - points[0].y()) / (points[1].x() - points[0].x()),
    k2 = (points[2].y() - points[0].y()) / (points[2].x() - points[0].x());

    if (k1 == k2) {
        throw validator_error("Введенные точки не образуют треугольник:\nвсе точки лежат на одной прямой");
    }

    return true;
}