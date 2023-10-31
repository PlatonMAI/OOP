#pragma once

#include <rectangleValidator.h>

class SquareValidator : public RectangleValidator {
public:
    virtual bool validate(std::vector<Point2D>&) override;
    virtual bool validate(Point2D&, Point2D&) override;
};