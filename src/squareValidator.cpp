#pragma once
#include <squareValidator.h>
#include <../src/square.cpp>

template <Number T>
bool SquareValidator<T>::validate(std::vector<Point2D<T>>& points) {
    // Квадрат - это прямоугольник с равными сторонами
    // На прямоугольник проверять умеем, проверим на равенство сторон

    RectangleValidator<T>::validate(points);

    std::vector<double> sides;
    std::vector<Point2D<T>> new_points = sortPoints<T>(points);
    for (int i = 0; i < 4; i += 2) {
        for (int j = 1; j < 4; j += 2) {
            sides.push_back( Vector<T>(new_points[i], new_points[j]).getLength() );
        }
    }

    std::sort(sides.begin(), sides.end());
    if (sides[0] != sides[3]) {
        throw validator_error("Введенные точки не образуют квадрат:\nстороны не равны");
    }

    return true;
}
template <Number T>
bool SquareValidator<T>::validate(Point2D<T>& a, Point2D<T>& c) {
    // Проверим сначала, можем ли построить прямоугольник
    // Затем выгоднее просто восстановить точки
    // и скормить стандартному валидатору

    RectangleValidator<T>::validate(a, c);

    std::vector<Point2D<T>> tmp( recoverPoints<T>(a, c) );
    validate(tmp);

    return true;
}