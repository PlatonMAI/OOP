#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

#include <../src/point2d.cpp>
#include <../src/vector.cpp>

template <Number T>
// class Figure : public std::enable_shared_from_this<Figure<T>> {
class Figure {
    template <Number T_>
    friend std::ostream& operator<<(std::ostream&, const Figure<T_>&);
    template <Number T_>
    friend std::istream& operator>>(std::istream&, Figure<T_>&);

public:
    Figure() = default;
    // Figure(std::vector<Point2D>&);

    // Конструкторы копирования и перемещения
    // Figure(const Figure&);
    Figure(Figure&&, int);

    // Операторы копирующего и перемещающего присваивания
    // Figure& operator=(const Figure&);
    Figure& operator=(Figure&&);

    // Геттеры для статических полей дочерних классов
    virtual int getVertices() const { return 0; }
    virtual std::string getName() const { return ""; }

    // Геометрия
    virtual Point2D<T> get_center() = 0;
    virtual operator double() = 0;

    std::vector<Point2D<T>> getPoints() const;

    ~Figure();

    // std::shared_ptr<Figure> getptr() { return shared_from_this(); }

protected:
    void builder(std::vector<Point2D<T>>&);
    void constructor(std::vector<Point2D<T>>&);

    Point2D<T>* _array;
};

// Точка пересечения двух прямых, заданных двумя точками
template <Number T>
Point2D<T> getIntersectionPoint(Point2D<T>&, Point2D<T>&, Point2D<T>&, Point2D<T>&);

// Длина вектора по двум точкам
template <Number T>
double getLengthVector(Point2D<T>&, Point2D<T>&);