#pragma once

#include <../src/figure.cpp>

template <Number T>
class Rectangle : public Figure<T> {
public:
    // using Figure::Figure;
    Rectangle(std::vector<Point2D<T>>&);
    // Прямоугольник можно однозначно восстановить по двум точкам, не лежащим на одной прямой
    Rectangle(Point2D<T>&, Point2D<T>&);
    Rectangle(const Rectangle&);
    Rectangle(Rectangle&& other) : Figure<T>(std::move(other), getVertices()) {}

    Rectangle& operator=(const Rectangle&);
    Rectangle& operator=(Rectangle&& other) {
        Figure<T>::operator=(std::move(other));
        return *this;
    }

    virtual int getVertices() const override { return vertices; }
    virtual std::string getName() const override { return name; }

    virtual Point2D<T> get_center() override;
    virtual operator double() override;

    static Rectangle create(std::vector<Point2D<T>>);
    static Rectangle create(Point2D<T>&, Point2D<T>&);
protected:
    static inline std::string name = "Прямоугольник";
    static inline int vertices = 4;
};

// Восстановить все точки прямоугольника по двум данным
template <Number T>
std::vector<Point2D<T>> recoverPoints(Point2D<T>&, Point2D<T>&);

template <Number T>
std::vector<Point2D<T>> sortPoints(std::vector<Point2D<T>>&);