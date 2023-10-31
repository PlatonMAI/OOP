#pragma once

#include <rectangle.h>

class Square : public Rectangle {
public:
    using Rectangle::Rectangle;

    virtual std::string getName() const override { return name; }

    static Square create(std::vector<Point2D>);
    static Square create(Point2D&, Point2D&);
protected:
    static inline std::string name = "Квадрат";
};