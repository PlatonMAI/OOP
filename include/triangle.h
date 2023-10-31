#pragma once

#include <figure.h>

class Triangle : public Figure {
    friend bool operator==(Triangle&, Triangle&);

public:
    // using Figure::Figure;
    Triangle(std::vector<Point2D>&);
    Triangle(const Triangle&);
    Triangle(Triangle&& other) : Figure(std::move(other), getVertices()) {}

    Triangle& operator=(const Triangle&);
    Triangle& operator=(Triangle&& other) {
        Figure::operator=(std::move(other));
        return *this;
    }

    virtual int getVertices() const override { return vertices; }
    virtual std::string getName() const override { return name; }

    virtual Point2D get_center() override;
    virtual operator double() override;

    static Triangle create(std::vector<Point2D>);

protected:
    static inline std::string name = "Треугольник";
    static inline int vertices = 3;
};