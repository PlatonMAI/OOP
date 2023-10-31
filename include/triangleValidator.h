#pragma once

#include <figureValidator.h>

class TriangleValidator : public FigureValidator {
public:
    virtual bool validate(std::vector<Point2D>&) override;
};