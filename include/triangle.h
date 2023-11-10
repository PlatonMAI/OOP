#pragma once

#include <../src/figure.cpp>

template <Number T>
class Triangle : public Figure<T> {
    template <Number T_>
    friend bool operator==(Triangle<T_>&, Triangle<T_>&);

public:
    // using Figure::Figure;
    Triangle(std::vector<Point2D<T>>&);
    Triangle(const Triangle&);
    Triangle(Triangle&& other) : Figure<T>(std::move(other), getVertices()) {}

    Triangle& operator=(const Triangle&);
    Triangle& operator=(Triangle&& other) {
        Figure<T>::operator=(std::move(other));
        return *this;
    }

    virtual int getVertices() const override { return vertices; }
    virtual std::string getName() const override { return name; }

    virtual Point2D<T> get_center() override;
    virtual operator double() override;

    static Triangle create(std::vector<Point2D<T>>);

protected:
    static inline std::string name = "Треугольник";
    static inline int vertices = 3;
};