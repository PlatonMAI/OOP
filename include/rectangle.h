#pragma once

#include <figure.h>

class Rectangle : public Figure {
public:
    // using Figure::Figure;
    Rectangle(std::vector<Point2D>&);
    // Прямоугольник можно однозначно восстановить по двум точкам, не лежащим на одной прямой
    Rectangle(Point2D&, Point2D&);
    Rectangle(const Rectangle&);
    Rectangle(Rectangle&& other) : Figure(std::move(other), getVertices()) {}

    Rectangle& operator=(const Rectangle&);
    Rectangle& operator=(Rectangle&& other) {
        Figure::operator=(std::move(other));
        return *this;
    }

    virtual int getVertices() const override { return vertices; }
    virtual std::string getName() const override { return name; }

    virtual Point2D get_center() override;
    virtual operator double() override;

    static Rectangle create(std::vector<Point2D>);
    static Rectangle create(Point2D&, Point2D&);
protected:
    static inline std::string name = "Прямоугольник";
    static inline int vertices = 4;
};

// Восстановить все точки прямоугольника по двум данным
std::vector<Point2D> recoverPoints(Point2D&, Point2D&);

std::vector<Point2D> sortPoints(std::vector<Point2D>&);