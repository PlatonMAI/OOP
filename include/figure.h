#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#include <point2d.h>
#include <vector.h>

class Figure {
    friend std::ostream& operator<<(std::ostream&, const Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);

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
    virtual Point2D get_center() = 0;
    virtual operator double() = 0;

    std::vector<Point2D> getPoints() const;

    ~Figure();

protected:
    void builder(std::vector<Point2D>&);
    void constructor(std::vector<Point2D>&);

    Point2D* _array;
};

// Точка пересечения двух прямых, заданных двумя точками
Point2D getIntersectionPoint(Point2D&, Point2D&, Point2D&, Point2D&);

// Длина вектора по двум точкам
double getLengthVector(Point2D&, Point2D&);