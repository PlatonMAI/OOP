#pragma once

#include <figureValidator.h>

class RectangleValidator : public FigureValidator {
public:
    virtual bool validate(std::vector<Point2D>&) override;
    virtual bool validate(Point2D&, Point2D&);
};